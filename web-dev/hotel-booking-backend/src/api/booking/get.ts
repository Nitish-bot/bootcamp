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
    where: { user_id: user.id, status },
    include: {
      hotel: {
        select: { name: true },
      },
      room: {
        select: {
          room_number: true,
          room_type: true,
        },
      },
    },
  })
  const bookingData = bookings.map(booking => {
    const orderedBooking = {
      id: booking.id,
      roomId: booking.room_id,
      hotelId: booking.hotel_id,
      hotelName: booking.hotel.name,
      roomNumber: booking.room.room_number,
      roomType: booking.room.room_type,
      checkInDate: booking.check_in_date,
      checkOutDate: booking.check_out_date,
      guests: booking.guests,
      totalPrice: booking.total_price,
      status: booking.status,
      bookingDate: booking.booking_date,
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
