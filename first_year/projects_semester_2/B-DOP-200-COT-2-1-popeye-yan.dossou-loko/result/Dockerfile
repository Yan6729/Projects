FROM node:20-alpine

WORKDIR /app

COPY package*.json ./

COPY . .

RUN npm install

RUN rm -rf node_modules

EXPOSE 80

CMD ["node", "server.js"]
