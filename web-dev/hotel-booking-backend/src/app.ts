import express from 'express'
import { requestValidator } from '@/validator-middleware'
import { signUpSchema, handleSignUp } from '@/api/auth/sign-up'
import { loginSchema, handleLogin } from '@/api/auth/login'

export function createApp() {
  const app = express()
  app.use(express.json())

  app.post('/api/auth/signup', requestValidator(signUpSchema), handleSignUp)
  app.post('/api/auth/login', requestValidator(loginSchema), handleLogin)

  return app
}
