import { db } from "@/db";
import type { ApiResponse, AuthenticatedRequest } from "@/types";
import type { Response } from "express";
import z from "zod";

export const addRoomSchema = z.object({
  roomNumber: z.string().nonempty().transform((val) => val?.toLowerCase()),
  roomType: z.string().nonempty().transform((val) => val?.toLowerCase()),
  pricePerNight: z.int(),
  maxOccupancy: z.int(),
})

const paramsSchema = z.object({
  hotelId: z.string()
})

type AddRoomRequest = z.infer<typeof addRoomSchema>

export async function handleAddRoom(req: AuthenticatedRequest, res: Response) {
  const parsedReq: AddRoomRequest = req.body
  const { hotelId } = paramsSchema.parse(req.params)

  const hotel = await db.hotel.findUnique({
    where: {id: hotelId},
    select: {owner_id: true, rooms: true}
  })

  if (!hotel) {
    const notFoundResponse: ApiResponse = {
      success: false,
      data: null,
      error: "HOTEL_NOT_FOUND"
    }
    return res.status(404).json(notFoundResponse)
  }

  const roomExists = hotel.rooms.find((room) => room.room_number == parsedReq.roomNumber)
  if (roomExists) {
    const roomExistsResponse: ApiResponse = {
      success: false,
      data: null,
      error: "ROOM_ALREADY_EXISTS"
    }
    return res.status(403).json(roomExistsResponse)
  }

  if (!req.user || req.user.role === 'customer' || req.user.id !== hotel.owner_id) {
    const forbiddenResponse: ApiResponse = {
      success: false,
      data: null,
      error: "FORBIDDEN"
    }
    return res.status(403).json(forbiddenResponse)
  }

  const room = await db.room.create({
    data: {
      room_number: parsedReq.roomNumber,
      room_type: parsedReq.roomType,
      price_per_night: parsedReq.pricePerNight,
      max_occupany: parsedReq.maxOccupancy,
      hotel_id: hotelId
    }
  })
  const orderedData = {
    id: room.id,
    hotelId: room.hotel_id,
    roomNumber: room.room_number,
    roomType: room.room_type,
    pricePerNight: room.price_per_night,
    maxOccupancy: room.max_occupany
  }
  const successResponse: ApiResponse = {
    success: true,
    data: orderedData,
    error: null
  }
  return res.status(201).json(successResponse)
} 