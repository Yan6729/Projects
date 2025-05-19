const express = require('express')
require("dotenv").config()
const authentification = require('./middleware/auth.js')
const connection = require('./config/db')
const todosRoutes = require('./routes/todos/todos.js');
const bodyParser = require('body-parser');
//const connection = require('./config/db')

const app = express()

app.use(express.urlencoded({extended: true}));
app.use(express.json())
app.use('/', require('./routes/auth/auth'))
app.use('/', authentification, require('./routes/user/user'))
app.use('/', require('./routes/todos/todos.js'))
//app.use(bodyParser.json())


const port = process.env.PORT || 3000

app.listen(port, () => {
    console.log('serveur en ligne')
})