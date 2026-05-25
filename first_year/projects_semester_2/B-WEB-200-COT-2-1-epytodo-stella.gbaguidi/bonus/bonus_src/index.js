const express = require('express')
require("dotenv").config()
const connection = require('./config/db')
const path = require('path');

const app = express()

app.use(express.json())
app.use(express.urlencoded({extended: true}))
app.use('/', require('./routes/auth/auth'))
app.use(express.static(path.join(__dirname, '../frontend')));
/*app.use('/user', require('./routes/user/user'))
app.use('/todos', require('./routes/todos/todos'))*/

const port = process.env.PORT || 3000

app.listen(port, () => {
    console.log('serveur en ligne')
})