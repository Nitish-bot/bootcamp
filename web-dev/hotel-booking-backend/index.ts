import { createApp } from './src/app';

const app = createApp();
const port = 5173;

app.listen(port, () => {
  console.log(`Now listening on port ${port}`);
});
