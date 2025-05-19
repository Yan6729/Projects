const express = require('express')
const route = express.Router()
const todos_query = require("./todos.query")
const view_todos = require("../../middleware/notFound")
const auth = require("../../middleware/auth")

  route.get('/todos', auth, (req, res) => {
        todos_query.alltodo(res);
    });

  route.get('/todos/:id', auth, view_todos, (req, res) => {
        todos_query.gettodoid(res, req.params.id);
    });

  route.post('/todos', auth, (req, res) => {
        const {title, description, duetime, status, user_id } = req.body;
        if (!title || !description || !duetime || !status || !user_id) {
            res.status(500).json({"msg":"internal server error"});
        }
        todos_query.createtodo(res, title, description, duetime, status, user_id, function (res) {
            res.status(400).json({"msg": "Bad parameter"});
        });
        //create_todo(res, title, description, duetime, user_id, status);
    });

  route.put('/todos/:id', auth, view_todos, (req, res) => {
        const {title, description, duetime, status, user_id } = req.body;
        if (!title || !description || !duetime || !status || !user_id) {
            res.status(400).json({"msg": "Bad parameter"});
        }
        todos_query.putuser(res, title, description, duetime, status, user_id, req.params.id, function (res) {
            res.status(404).json({"msg": "Not found"});
        });
    });

  route.delete('/todos/:id', auth, view_todos, (req, res) => {
        todos_query.deletetodo(res, req.params.id, function (res) {
            res.status(500).json({"msg":"Internal server error"});
        });
    });
  
    module.exports = route
