import type { NextFunction, Request, Response } from 'express'
import { type ZodType } from 'zod'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import { jwtVerify } from 'jose'
import { env } from 'bun'
import type { Role } from '@/generated/prisma/enums'

export function requestValidator(schema: ZodType) {
  return (req: Request, res: Response, next: NextFunction) => {
    const result = schema.safeParse(req.body)

    if (!result.success) {
      for (const issue of result.error.issues) {
        console.log(issue)
        if (issue.code == 'invalid_type') {
          const response: ApiResponse = {
            success: false,
            data: null,
            error: 'INVALID_REQUEST',
          }
          return res.status(400).json(response)
        }
      }
    }

    req.body = result.data

    next()
  }
}

export async function jwtValidator(
  req: AuthenticatedRequest,
  res: Response,
  next: NextFunction
) {
  console.log(req.headers)
  const authHeader = req.headers['authorization']
  console.log(authHeader)
  const token = authHeader && authHeader.split(' ')[1]

  const unauthResponse: ApiResponse = {
    success: false,
    data: null,
    error: 'UNAUTHORIZED',
  }
  if (!token) {
    return res.status(401).json(unauthResponse)
  }

  try {
    const jwtSecretKey = new TextEncoder().encode(env.JWT_SECRET_KEY)
    const { payload, protectedHeader } = await jwtVerify(token, jwtSecretKey)
    console.log(payload)
    console.log(protectedHeader)
    if (!payload.sub || !payload.role) {
      return res.status(401).json({
        success: false,
        data: null,
        error: 'INVALID_TOKEN_PAYLOAD',
      })
    }
    const user = {
      id: payload.sub,
      role: payload.role as Role,
    }
    req.user = user
    next()
  } catch (e) {
    console.log(e)
    return res.status(401).json(unauthResponse)
  }
}
