const notfound = (req, res) => {
    res.status(404).json({msg: 'Not found'})
}

module.exports = notfound