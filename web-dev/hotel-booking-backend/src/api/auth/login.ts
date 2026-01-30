import { type Request, type Response } from "express";
import z from "zod";
import { compare } from 'bcrypt'
import { db } from "../../db";
import type { ApiResponse } from "../../types";
import { env } from "bun";
import { SignJWT } from "jose";

export const loginSchema = z.object({
  email: z.email(),
  password: z.string(),
})

type LoginRequest = z.infer<typeof loginSchema>

export async function handleLogin(req: Request, res: Response) {
  const parsedReq: LoginRequest = req.body
  const invalidCredentialResponse: ApiResponse = {
    success: false,
    data: null,
    error: "INVALID_CREDENTIALS",
  }  

  const possibleUser = await db.user.findUnique({
    where: {email: parsedReq.email}
  })
  if (!possibleUser) {
    return res.status(401).json(invalidCredentialResponse)
  }

  const isPasswordCorrect = await compare(parsedReq.password, possibleUser.password)
  if (isPasswordCorrect) {
    const jwtSecretKey = new TextEncoder().encode(env.JWT_SECRET_KEY)
    const tokenData = {
      sub: possibleUser.id,
      role: possibleUser.role,
      time: Date(),
    }

    const token = await new SignJWT(tokenData)
      .setProtectedHeader({alg: 'HS256'})
      .setIssuedAt()
      .setExpirationTime('12h')
      .sign(jwtSecretKey)

    const responseData = {
      token,
      user: {
        id: possibleUser.id,
        name: possibleUser.name,
        email: possibleUser.email,
        role: possibleUser.role
      }
    }
    const successResponse: ApiResponse = {
      success: true,
      data: responseData,
      error: null,
    }

    return res.status(200).json(successResponse)
  } else {
    return res.status(401).json(invalidCredentialResponse)
  }
}