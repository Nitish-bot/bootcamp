import express from 'express'
import { jwtValidator, requestValidator } from '@/validator-middleware'
import { signUpSchema, handleSignUp } from '@/api/auth/sign-up'
import { loginSchema, handleLogin } from '@/api/auth/login'
import { createHotelSchema, handleCreateHotel } from '@/api/hotels/create'
import { addRoomSchema, handleAddRoom } from '@/api/hotels/addRoom'
import { handleGetHotels } from '@/api/hotels/getHotels'
import { handleGetSingularHotel } from '@/api/hotels/getSingular'
import { createBookingSchema, handleCreateBooking } from '@/api/booking/create'
import { handleGetBooking } from '@/api/booking/get'
import { handleCancelBooking } from '@/api/booking/cancel'
import { createReviewSchema, handleCreateReview } from '@/api/reviews/create'

export function createApp() {
  const app = express()
  app.use(express.json())

  app.post('/api/auth/signup', requestValidator(signUpSchema), handleSignUp)
  app.post('/api/auth/login', requestValidator(loginSchema), handleLogin)

  app.post(
    '/api/hotels',
    [requestValidator(createHotelSchema), jwtValidator],
    handleCreateHotel
  )
  app.post(
    '/api/hotels/:hotelId/rooms',
    [requestValidator(addRoomSchema), jwtValidator],
    handleAddRoom
  )
  app.get('/api/hotels', jwtValidator, handleGetHotels)
  app.get('/api/hotels/:hotelId', jwtValidator, handleGetSingularHotel)

  app.post(
    '/api/bookings',
    [requestValidator(createBookingSchema), jwtValidator],
    handleCreateBooking
  )
  app.put('/api/bookings/:bookingId/cancel', jwtValidator, handleCancelBooking)
  app.get('/api/bookings', jwtValidator, handleGetBooking)

  app.post(
    '/api/reviews',
    [requestValidator(createReviewSchema), jwtValidator],
    handleCreateReview
  )

  return app
}
