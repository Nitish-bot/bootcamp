import { db } from "@/db";
import type { ApiResponse, AuthenticatedRequest } from "@/types";
import type { Response } from "express";
import z from "zod";

const paramsSchema = z.object({
  hotelId: z.string()
})

export async function handleGetSingularHotel(req: AuthenticatedRequest, res: Response) {
  const { hotelId } = paramsSchema.parse(req.params)
  const hotel = await db.hotel.findUnique({
    where: {id: hotelId},
    include: {
      rooms: true
    }
  })

  if (!hotel) {
    const notFoundResponse: ApiResponse = {
      success: false,
      data: null,
      error: "HOTEL_NOT_FOUND"
    }
    return res.status(404).json(notFoundResponse)
  }

  const orderedHotel = {
    id: hotel.id,
    ownerId: hotel.owner_id,
    name: hotel.name,
    description: hotel.description,
    city: hotel.city,
    country: hotel.country,
    amenities: hotel.amenities,
    rating: hotel.rating,
    totalReviews: hotel.total_reviews,
    rooms: hotel.rooms,
  }
  const successResponse: ApiResponse = {
    success: true,
    data: orderedHotel,
    error: null,
  }

  return res.status(200).json(successResponse)
}