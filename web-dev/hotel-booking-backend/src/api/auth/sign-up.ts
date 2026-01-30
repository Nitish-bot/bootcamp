import type { Request, Response } from 'express'
import { z } from 'zod'
import { db } from '@/db'
import type { ApiResponse } from '@/types'
import { Role } from '@/generated/prisma/enums'
import { genSalt, hash } from 'bcrypt'

export const signUpSchema = z.object({
  name: z.string().nonempty(),
  email: z.email().nonempty(),
  password: z.string().nonempty(),
  role: z
    .string()
    .optional()
    .transform(val => val?.toLowerCase())
    .pipe(z.enum(Role))
    .default(Role.customer),
  phone: z.string().optional(),
})

type SignUpRequest = z.infer<typeof signUpSchema>

export async function handleSignUp(req: Request, res: Response) {
  const parsedReq: SignUpRequest = req.body

  const emailExists = await db.user.findUnique({ where: { email: parsedReq.email } })
  if (emailExists) {
    const response: ApiResponse = {
      success: false,
      data: null,
      error: 'EMAIL_ALREADY_EXISTS',
    }
    return res.status(400).json(response)
  }

  const salt = await genSalt(10)
  const hashedPass = await hash(parsedReq.password, salt)

  const newUser = await db.user.create({
    data: {
      ...parsedReq,
      password: hashedPass,
    },
    select: {
      id: true,
      name: true,
      email: true,
      role: true,
      phone: true,
    },
  })

  const orderedUser = {
    id: newUser.id,
    name: newUser.name,
    email: newUser.email,
    role: newUser.role,
    phone: newUser.phone,
  }

  const successResponse: ApiResponse = {
    success: true,
    data: orderedUser,
    error: null,
  }
  return res.status(201).json(successResponse)
}
