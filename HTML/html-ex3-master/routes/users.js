var express = require('express');
const bodyParser = require('body-parser');
var router = express.Router();

const jsonParser = bodyParser.json();

var array = [];

/* GET users listing. */
router.get('/', (req, res, next) => {
    const data = JSON.stringify({ value: array });
    res.send(data);
});

router.post('/', jsonParser, (req, res, next) => {
    for (val of array)
        if (val == req.body.value)
            return res.send(JSON.stringify({ value: false }));
    array.push(req.body.value);
    return res.send(JSON.stringify({ value: true }));
});

router.delete('/', jsonParser, (req, res, next) => {
    for (i in array)
        if (array[i] == req.body.value)
            array.splice( i, 1 );

    const data = JSON.stringify({ value: array });
    res.send(data);
});

module.exports = router;
