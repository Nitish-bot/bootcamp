import type { NextFunction, Request, Response } from 'express'
import type { ZodType } from 'zod'
import type { ApiResponse } from './types'

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

export function jwtValidator(req: Request, res: Response, next: NextFunction) {
  const authHeader = req.headers['authorization']
  const token = authHeader && authHeader.split(" ")[1]

  const unauthResponse: ApiResponse = {
    success: false,
    data: null,
    error: "UNAUTHORIZED"
  }
  if (!token) {
    return res.status(401).json(unauthResponse)
  }
}
