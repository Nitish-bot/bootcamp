import express from 'express'
import { validatorMiddleware } from './validator-middleware'
import { signUpSchema, handleSignUp } from './api/auth/sign-up'

export function createApp() {
  const app = express()
  app.use(express.json())

  app.post('/api/auth/signup', validatorMiddleware(signUpSchema), handleSignUp)

  return app
}
