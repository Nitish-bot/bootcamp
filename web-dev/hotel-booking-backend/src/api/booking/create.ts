import { db } from '@/db'
import { BookingStatus } from '@/generated/prisma/enums'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import type { Response } from 'express'
import z from 'zod'

export const createBookingSchema = z.object({
  roomId: z.string().nonempty(),
  checkInDate: z.date(),
  checkOutDate: z.date(),
  guests: z.number().int(),
})

type createBookingRequest = z.infer<typeof createBookingSchema>

const ONE_DAY = 24 * 60 * 60 * 1000
export async function handleCreateBooking(req: AuthenticatedRequest, res: Response) {
  const user = req.user
  if (!user || user.role !== 'customer') {
    const forbiddenResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'FORBIDDEN',
    }
    return res.status(403).json(forbiddenResponse)
  }

  const { roomId, checkInDate, checkOutDate, guests }: createBookingRequest = req.body

  const booking_length = checkOutDate.getDate() - checkInDate.getDate()
  const nights = booking_length / ONE_DAY
  if (nights < 1) {
    const invalidDatesResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'ROOM_NOT_FOUND',
    }
    return res.status(404).json(invalidDatesResponse)
  }

  const room = await db.room.findUnique({
    where: { id: roomId },
    select: {
      id: true,
      hotel_id: true,
      price_per_night: true,
      max_occupany: true,
      booking: true,
    },
  })
  if (!room) {
    const notFoundRespone: ApiResponse = {
      success: false,
      data: null,
      error: 'ROOM_NOT_FOUND',
    }
    return res.status(404).json(notFoundRespone)
  }
  if (guests > room.max_occupany) {
    const invalidCapacityResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'INVALID_CAPACITY',
    }
    return res.status(404).json(invalidCapacityResponse)
  }

  const isBooked = room.booking.some(booking => {
    return !(checkInDate > booking.check_out_date || checkOutDate < booking.check_in_date)
  })
  if (isBooked) {
    const roomUnavailableResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'ROOM_NOT_AVAILABLE',
    }
    return res.status(404).json(roomUnavailableResponse)
  }

  const atomicBooking = await db.$transaction(async tx => {
    const totalPrice = nights * room.price_per_night
    const bookingData = {
      user_id: user.id,
      room_id: room.id,
      hotel_id: room.hotel_id,
      check_in_date: checkInDate,
      check_out_date: checkOutDate,
      guests: guests,
      total_price: totalPrice,
      status: BookingStatus.confirmed,
    }
    const booking = await tx.booking.create({
      data: bookingData,
    })
    return booking
  })

  const orderedBooking = {
    id: atomicBooking.id,
    userId: atomicBooking.user_id,
    roomId: atomicBooking.room_id,
    hotelId: atomicBooking.hotel_id,
    checkInDate,
    checkOutDate,
    guests,
    totalPrice: atomicBooking.total_price,
    status: atomicBooking.status,
    bookingDate: atomicBooking.booking_date,
  }
  const successResponse: ApiResponse = {
    success: true,
    data: orderedBooking,
    error: null,
  }

  return res.status(201).json(successResponse)
}
