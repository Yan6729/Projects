const express = require('express')
const route = express.Router()
const cors = require('cors')
const path = require('path')
const bcrypt = require('bcryptjs')
const jsonweb = require('jsonwebtoken')
const connection = require('../../config/db')
const authentication = require('../../middleware/auth')
require('dotenv').config()
                              
route.use(cors());
route.get('/register', (req, res) => {
    res.sendFile(path.join(__dirname + '../../../../frontend/register.html'))
})
route.post('/register', (req, res) => {
    //je crée uns sorte de tableau commebody pour récupérer les informations du user
    const { email, password, name, firstname } = req.body
    //renvoyer le message d'erreur quand il manque une info
    if (!email || !password || !name || !firstname)
        return res.status(400).json({ msg: 'Bad parameter'})
    connection.query("SELECT * FROM user WHERE email = ?", [email], function (err, result) {
        if (err) {
            return res.status(500).json({msg: "erreur de connexion à mysql"})
        }
        if (result.length > 0) {
            return res.status(401).json( {"msg": "Account already exists"} )
        }
        //hashage du mot de passe
        bcrypt.hash(password, 10, (err, hshpswd) => {
            if (err) {
                return res.status(500).json({"msg": "Internal server error"})
            }
            //j'insère les informations dans les données de ma table user
            connection.query('INSERT INTO user (email, password, name, firstname) VALUES (?, ?, ?, ?)',
                [email, hshpswd, name, firstname], (err, result) => {
                    if (err) {
                        console.log(err)
                        return res.status(500).json({"msg": "erreur d'insertion"})
                    }
                    const token = jsonweb.sign({id: result.insertId}, process.env.SECRET, {expiresIn: '1h'})
                    console.log(token)
                    return res.status(201).json( {token: "Token of the newly registered user"})
            })
        })
    })
})

route.use(cors());
route.get('/login', (req, res) => {
    res.sendFile(path.join(__dirname + '../../../../frontend/index.html'))
})
route.post('/login', (req, res) => {
    const { email, password } = req.body
    if (!email || !password)
        return res.status(400).json({ msg: 'Bad parameter'})
    connection.query('SELECT *FROM user WHERE email = ?', [email], (err, result) => {
        if (err) {
            return res.status(400).json({ msg: 'erreur de connexion à mysql'})
        }
        if (result.length === 0)
            return res.status(201).json( {"msg": "Account doesn't exist"} )
        const user = result[0];
        bcrypt.compare(password, result[0].password, (err, isMatch) => {
            if (err)
                return res.status(400).json({msg: "erreur de comparaison"})
            if (!isMatch)
                return res.status(201).json({"msg": "Invalid Credentials" })
            const token = jsonweb.sign({id: result[0].id}, process.env.SECRET, {expiresIn: '1h'})
            console.log(token)
            return res.status(201).json({token: "Token of the newly logged in user" })
        })
    })
})

module.exports = route