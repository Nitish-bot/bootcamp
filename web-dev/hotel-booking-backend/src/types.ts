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
