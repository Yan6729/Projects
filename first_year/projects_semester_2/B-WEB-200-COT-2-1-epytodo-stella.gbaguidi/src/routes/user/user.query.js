const connection = require('../../config/db')

exports.get_user = (callback) => {
    connection.query("SELECT * FROM user", callback)
}

exports.get_user_todos = (callback) => {
    connection.query("SELECT * FROM todo", callback)
}

exports.get_userbyidoremail = (id, callback) => {
    if (!isNaN(id)) {
        connection.query("SELECT * FROM user WHERE id = ?", [id], callback)
    } else {
        connection.query("SELECT * FROM user WHERE email = ?", [id], callback)
    }
}

exports.put_user = (info, id, callback) => {
    connection.query("UPDATE user SET (email, firstname, name, password) WHERE id ",
        [info.email, info.firstname, info.name, info.password, id], callback)
}

exports.del_user = (id, callback) => {
    connection.query("DELETE FROM user WHERE id = ?", [id], callback)
}