import { db } from '@/db'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import type { Response } from 'express'
import z from 'zod'

export const createReviewSchema = z.object({
  bookingId: z.string().nonempty(),
  rating: z.int().min(0).max(5),
  comment: z.string().nonempty(),
})

type createReviewRequest = z.infer<typeof createReviewSchema>

export async function handleCreateReview(req: AuthenticatedRequest, res: Response) {
  const { bookingId, rating, comment }: createReviewRequest = req.body

  const booking = await db.booking.findUnique({
    where: { id: bookingId },
    include: { review: true, hotel: true },
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
  if (booking.review) {
    const alreadyReviewedResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'ALREADY_REVIEWED',
    }
    return res.status(400).json(alreadyReviewedResponse)
  }

  const today = new Date().setHours(0, 0, 0, 0)
  if (booking.checkOutDate.getMilliseconds() > today || booking.status === 'cancelled') {
    const bookingNotEligibleResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'BOOKING_NOT_ELIGIBLE',
    }
    return res.status(400).json(bookingNotEligibleResponse)
  }

  const review = await db.review.create({
    data: {
      userId: req.user.id,
      hotelId: booking.hotelId,
      bookingId: booking.id,
      rating,
      comment,
    },
  })

  const currentRating = booking.hotel.rating
  const totalReviews = booking.hotel.totalReviews
  const newRating = (currentRating * totalReviews + rating) / totalReviews + 1
  db.hotel.update({
    where: { id: booking.hotelId },
    data: {
      ...booking.hotel,
      amenities: booking.hotel.amenities as string[],
      rating: newRating,
      totalReviews: totalReviews + 1,
    },
  })

  const orderedReview = {
    id: review.id,
    userId: review.userId,
    hotelId: review.hotelId,
    bookingId: review.bookingId,
    rating: review.rating,
    comment: review.comment,
    createdAt: review.createdAt,
  }
  const successResponse: ApiResponse = {
    success: true,
    data: orderedReview,
    error: null,
  }

  return res.status(201).json(successResponse)
}
