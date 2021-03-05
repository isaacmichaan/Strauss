var express = require('express');
var router = express.Router();

var User = require('../models/user1');

const bodyParser = require('body-parser');
const jsonParser = bodyParser.json();


/* GET users listing. */
router.get('/', async (req, res, next) => {
  let a = await User.getAllUsers();
  let arr = [];
  for (let i = 0; i < a.length; i++)
    arr.push(a[i].name);
  const data = JSON.stringify({ value: arr });
  res.send(data);
});

router.post('/', jsonParser, (req, res, next) => {
  User.getUserByName(req.body.value).then(async (user) => {
    if (!user)
        await User.createUser(req.body.value);
    return res.send(JSON.stringify({ value: !user }));
  });
});

router.delete('/', jsonParser, async (req, res, next) => {
  User.deleteUserByName(req.body.value).then(async () => {
    let a = await User.getAllUsers();
    let arr = [];
    for (let i = 0; i < a.length; i++)
      arr.push(a[i].name);
    const data = JSON.stringify({ value: arr });
    res.send(data);
  });
});

module.exports = router;