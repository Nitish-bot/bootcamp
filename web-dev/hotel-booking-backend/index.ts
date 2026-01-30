import { env } from 'bun'
import { createApp } from '@/app'

const app = createApp()
const port = env.PORT

app.listen(port, () => {
  console.log(`Now listening on port ${port}`)
})
