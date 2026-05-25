const express = require('express')
const app = express()
const port = 3000
const http = require("node:http");
const fs = require("node:fs")

app.get('/html/:user', (req, res) => {
    const name = req.params['user']
    res.writeHead(200, {"Content-Type": "text/html" })
    res.end(`<p>Hello ${name}!</p>`)
})

app.get('/', (req, res) => {
  res.send('Welcome to my first site web !')
})

app.get('/home/:user', (req, res) => {
    const name = req.params['user']
    const str = 'Welcome ' + name + '\n'
  res.send(str)
})

app.get('/id/:user', (req, res) => {
    const name = req.params.user
    const str = `Welcome ${name}`
  res.json({Message: str})
})

app.get('/date', (req, res) => {
    const date = new Date().toISOString().split('T')
    const date2 = new Date().toTimeString().split(' ')
    res.send(date[0]+ ' ' + date2[0])
})


app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
