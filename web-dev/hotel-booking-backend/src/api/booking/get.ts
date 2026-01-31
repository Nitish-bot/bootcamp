import z from 'zod'
import { BookingStatus } from '@/generated/prisma/enums'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import type { Response } from 'express'
import { db } from '@/db'

export const querySchema = z.object({
  status: z
    .string()
    .transform(val => val?.toLowerCase())
    .pipe(z.enum(BookingStatus))
    .optional(),
})

export async function handleGetBooking(req: AuthenticatedRequest, res: Response) {
  const user = req.user
  if (!user || user.role !== 'customer') {
    const forbiddenResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'FORBIDDEN',
    }
    return res.status(403).json(forbiddenResponse)
  }

  const { status } = querySchema.parse(req.query)
  const bookings = await db.booking.findMany({
    where: { userId: user.id, status },
    include: {
      hotel: {
        select: { name: true },
      },
      room: {
        select: {
          roomNumber: true,
          roomType: true,
        },
      },
    },
  })
  const bookingData = bookings.map(booking => {
    const orderedBooking = {
      id: booking.id,
      roomId: booking.roomId,
      hotelId: booking.hotelId,
      hotelName: booking.hotel.name,
      roomNumber: booking.room.roomNumber,
      roomType: booking.room.roomType,
      checkInDate: booking.checkInDate,
      checkOutDate: booking.checkOutDate,
      guests: booking.guests,
      totalPrice: booking.totalPrice,
      status: booking.status,
      bookingDate: booking.bookingDate,
    }
    return orderedBooking
  })
  const successResponse: ApiResponse = {
    success: true,
    data: bookingData,
    error: null,
  }

  return res.status(200).json(successResponse)
}
