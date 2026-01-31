import { db } from '@/db'
import type { ApiResponse, AuthenticatedRequest } from '@/types'
import type { Response } from 'express'
import z from 'zod'

export const createHotelSchema = z.object({
  name: z.string().nonempty(),
  description: z.string().nonempty(),
  city: z
    .string()
    .nonempty()
    .transform(val => val?.toLowerCase()),
  country: z
    .string()
    .nonempty()
    .transform(val => val?.toLowerCase()),
  amenities: z.array(z.string()).optional().default([]),
})

type CreateHotelRequest = z.infer<typeof createHotelSchema>

export async function handleCreateHotel(req: AuthenticatedRequest, res: Response) {
  if (!req.user || req.user.role === 'customer') {
    const forbiddenResponse: ApiResponse = {
      success: false,
      data: null,
      error: 'FORBIDDEN',
    }
    return res.status(403).json(forbiddenResponse)
  }

  const parsedReq: CreateHotelRequest = req.body
  const hotel = await db.hotel.create({
    data: {
      ...parsedReq,
      owner_id: req.user.id,
      rating: 0.0,
      total_reviews: 0
    },
  })

  const orderedData = {
    id: hotel.id,
    ownerId: hotel.owner_id,
    name: hotel.name,
    description: hotel.description,
    city: hotel.city,
    country: hotel.country,
    amenities: hotel.amenities,
    rating: 0.0,
    totalReviews: 0,
  }
  const successResponse: ApiResponse = {
    success: true,
    data: orderedData,
    error: null,
  }
  return res.status(201).json(successResponse)
}
