import { db } from '@/db'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import type { Response } from 'express'
import z from 'zod'

const paramsSchema = z.object({
  bookingId: z.string(),
})

export async function handleCancelBooking(req: AuthenticatedRequest, res: Response) {
  const { bookingId } = paramsSchema.parse(req.params)
  const booking = await db.booking.findUnique({
    where: { id: bookingId },
  })
  if (!booking) {
    const notFoundResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'BOOKING_NOT_FOUND',
    }
    return res.status(404).json(notFoundResponse)
  }
  if (!req.user || req.user.role !== 'customer' || req.user.id !== booking?.userId) {
    const forbiddenResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'FORBIDDEN',
    }
    return res.status(403).json(forbiddenResponse)
  }
  if (booking.status === 'cancelled') {
    const alreadyCancelledResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'ALREADY_CANCELLED',
    }
    return res.status(400).json(alreadyCancelledResponse)
  }

  const ONE_HOUR = 60 * 60 * 1000
  const today = new Date()
  const hourDifference =
    (booking.checkInDate.getMilliseconds() - today.getMilliseconds()) / ONE_HOUR
  if (hourDifference < 24) {
    const deadlinePassedResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'CANCELLATION_DEADLINE_PASSED',
    }
    return res.status(403).json(deadlinePassedResponse)
  }

  const updatedBooking = await db.booking.update({
    where: { id: bookingId },
    data: {
      ...booking,
      status: 'cancelled',
      cancelledAt: today,
    },
  })
  const orderedBooking = {
    id: updatedBooking.id,
    status: updatedBooking.status,
    cancelledAt: updatedBooking.cancelledAt,
  }
  const successResponse: ApiResponse = {
    success: true,
    data: orderedBooking,
    error: null,
  }

  return res.status(200).json(successResponse)
}
