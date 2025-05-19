const express = require('express')
const route = express.Router()
require('dotenv').config()
const authentification = require('../../middleware/auth')
const user_query = require('./user.query')
const notfound = require('../../middleware/notFound')
                                                                                                                                          
route.get('/user', authentification, (req, res) => {
    user_query.get_user(function (err, result) {
        if (err)
            return res.status(500).json({msg: 'erreur de connexion à mysql'})
        if (result.length === 0)
            return res.status(404).json({msg: 'user not found'})
        return res.status(200).json(result)
    })
})

route.get('/user/todos', authentification, (req, res) => {
    user_query.get_user_todos(function (err, result) {
        if (err)
            return res.status(500).json({msg: 'erreur de connexion à mysql'})
        if (result.length === 0)
            return res.status(404).json({msg: 'user not found'})
        return res.status(200).json(result)
    })
})

route.get('/users/:id', authentification, (req, res) => {
    const id = req.params.id
    user_query.get_userbyidoremail([id], function(err, result) {
        if (err)
            return res.status(500).json({msg: 'erreur de connexion à mysql'})
        if (result.length === 0)
            return res.status(404).json({msg: 'user not found'})
        return res.status(200).json(result)
    })
    
})
route.put('/users/:id', authentification, (req, res) => {
    const info = {email, firstname, name, password} = req.body
    if (req.user.id !== parseInt(req.params.id))
        return res.status(403).json({msg: "Internal server error"})
    if (!info.email || !info.password || !info.name || !info.firstname)
        return res.status(400).json({ msg: 'Bad parameter'})
    user_query.put_user([info, id], function(err, result) {
        if (err)
            return res.status(500).json({msg: 'erreur de connexion à mysql'})
        if (result.length === 0)
            return res.status(404).json({msg: 'user not found'})
        return res.status(200).json(result)
    })
})

route.delete('/users/:id', authentification, (req, res) => {
    const id = req.params.id
    user_query.del_user([id], function(err, result) {
        if (err)
            return res.status(500).json({msg: 'erreur de connexion à mysql'})
        if (result.length === 0)
            return res.status(404).json({msg: 'user not found'})
        return res.status(200).json({msg: "Successfully deleted record number: ${id}"})
    })
})
module.exports = route