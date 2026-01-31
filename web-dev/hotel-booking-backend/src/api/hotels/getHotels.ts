import { db } from '@/db'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import type { Response } from 'express'
import z from 'zod'

const querySchema = z.object({
  city: z
    .string()
    .transform(val => val?.toLowerCase())
    .optional(),
  country: z
    .string()
    .transform(val => val?.toLowerCase())
    .optional(),
  minPrice: z.coerce.number().int().optional(),
  maxPrice: z.coerce.number().int().optional(),
  minRating: z.int().min(0).max(5).optional(),
})

export async function handleGetHotels(req: AuthenticatedRequest, res: Response) {
  const query = querySchema.parse(req.query)

  let hotels = await db.hotel.findMany({
    where: {
      city: query.city,
      country: query.country,
    },
    include: {
      rooms: true,
      reviews: true,
    },
  })

  if (query.minPrice !== undefined) {
    const minPrice = query.minPrice
    hotels = hotels.filter(hotel =>
      hotel.rooms.some(room => room.price_per_night > minPrice)
    )
  }

  if (query.maxPrice !== undefined) {
    const maxPrice = query.maxPrice
    hotels = hotels.filter(hotel =>
      hotel.rooms.some(room => room.price_per_night < maxPrice)
    )
  }

  hotels.filter(hotel => hotel.rooms.length > 0)

  const structuredHotels = hotels.map(hotel => {
    const lowestPrice = Math.min(...hotel.rooms.map(room => room.price_per_night))
    return {
      id: hotel.id,
      name: hotel.name,
      description: hotel.description,
      city: hotel.city,
      country: hotel.country,
      amenities: hotel.amenities,
      rating: hotel.rating,
      totalReviews: hotel.reviews.length,
      minPricePerNight: lowestPrice,
    }
  })

  if (query.minRating !== undefined) {
    const minRating = query.minRating
    structuredHotels.filter(hotel => hotel.rating > minRating)
  }

  const successResponse: ApiResponse = {
    success: true,
    data: structuredHotels,
    error: null,
  }
  return res.status(200).json(successResponse)
}
