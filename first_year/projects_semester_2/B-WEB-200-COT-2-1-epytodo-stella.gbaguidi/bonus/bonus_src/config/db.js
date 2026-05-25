const mysql = require('mysql2')
require("dotenv").config()

//chaîne de connexion
const connection = mysql.createConnection({
host: process.env.MYSQL_HOST,
user: process.env.MYSQL_USER,
password: process.env.MYSQL_ROOT_PASSWORD,
database: process.env.MYSQL_DATABASE,
})

//connection
connection.connect(err=> {
   if (err) {
      console.log('erreur de connexion')
   } else {
      console.log('Connecté à mysql')
   }
})
module.exports = connection