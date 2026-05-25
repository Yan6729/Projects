const express = require('express')
const route = express.Router()
const bcrypt = require('bcryptjs')
const jsonweb = require('jsonwebtoken')
const connection = require('../../config/db')
require('dotenv').config()
                                                                                                                                          
route.post('/register', (req, res) => {
    //je crée uns sorte de tableau commebody pour récupérer les informations du user
    const { email, password, name, firstname } = req.body
    //renvoyer le message d'erreur quand il manque une info
    if (!email || !password || !name || !firstname)
        return res.status(400).json({ msg: 'Bad parameter'})
    n_date = new Date().toISOString().split('T')
    n_hour = new Date().toTimeString().split(' ')
    const date = n_date[0] + ' ' + n_hour[0]
    connection.query("SELECT * FROM user WHERE email = ?", [email], function (err, result) {
        if (err) {
            return res.status(500).json({msg: "erreur de connexion à mysql"})
        }
        if (result.length > 0) {
            return res.status(409).json( {"msg": "Account already exists"} )
        }
        //hashage du mot de passe
        bcrypt.hash(password, 10, (err, hshpswd) => {
            if (err) {
                return res.status(500).json({"msg": "Internal server error"})
            }
            //j'insère les informations dans les données de ma table user
            connection.query('INSERT INTO user (email, password, name, firstname, created_at) VALUES (?, ?, ?, ?, ?)',
                [email, hshpswd, name, firstname, date], (err, result) => {
                    if (err) {
                        console.log(err)
                        return res.status(500).json({"msg": "erreur d'insertion"})
                    }
                    let token = jsonweb.sign({id: result.insertId}, process.env.SECRET, {expiresIn: '1h'})
                    return res.status(201).json( {token: `${token}`})
            })
        })
    })
})

route.post('/login', (req, res) => {
//je crée uns sorte de tableau commebody pour récupérer les informations du user
    const { email, password } = req.body
    if (!email || !password)
        return res.status(400).json({ msg: 'Bad parameter'})
//je vérifie si le mail existe dans la base de données 
    connection.query('SELECT * FROM user WHERE email = ?', [email], (err, result) => {
        if (err) {
            return res.status(400).json({ msg: 'erreur de connexion à mysql'})
        }
        if (result.length === 0)
            return res.status(404).json( {msg: "Account don't exist"} )
        //je compare le password entré avec le password initial
        bcrypt.compare(password, result[0].password, (err, result) => {
            if (err)
                return res.status(400).json({msg: "erreur de comparaison"})
            if (!result)
                return res.status(401).json({msg: "Invalid Credentials" })
            const token = jsonweb.sign({id: res.id}, process.env.SECRET, {expiresIn: '1h'})
            console.log(token)
            return res.status(200).json({token: `${token}`})
        })
    })
})

module.exports = route