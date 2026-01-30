import type { Request } from "express"
import type { Role } from "./generated/prisma/enums"

export type ApiResponse<T = unknown> =
  | {
      success: true
      data: T
      error: null
    }
  | {
      success: false
      data: null
      error: string
    }

type User = {
  id: string
  role: Role
}

export type AuthenticatedRequest = Request & {
  user?: User
}