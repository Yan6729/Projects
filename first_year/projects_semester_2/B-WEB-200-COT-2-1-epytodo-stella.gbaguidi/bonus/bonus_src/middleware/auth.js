const jsonweb = require('jsonwebtoken')
require('dotenv').config()


const authentication = function(req, res, next) {
    //recupérer le token envoyé par l'utilisateur
    const token = req.header('Authorization') && req.header('Authorization').split(' ')[1]
    if (!token) {
        return res.status(401).json({ "msg": "No token, authorization denied" })
    }
    //vérifier si le token est correcte   
    try {                   
        const code = jsonweb.verify(token, process.env.SECRET)
    //mettre les données dans req.user si c'est bon
        req.user = code
    //continuer vers le route demandée
        next()
    } catch (err) {
        return res.status(401).json({ "msg": "Token is not valid" })
    }
}
module.exports = authentication