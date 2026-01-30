import express from 'express'
import { jwtValidator, requestValidator } from '@/validator-middleware'
import { signUpSchema, handleSignUp } from '@/api/auth/sign-up'
import { loginSchema, handleLogin } from '@/api/auth/login'
import { createHotelSchema, handleCreateHotel } from './api/hotels/create'

export function createApp() {
  const app = express()
  app.use(express.json())

  app.post('/api/auth/signup', requestValidator(signUpSchema), handleSignUp)
  app.post('/api/auth/login', requestValidator(loginSchema), handleLogin)
  app.post('/api/hotels', [requestValidator(createHotelSchema), jwtValidator], handleCreateHotel)

  return app
}