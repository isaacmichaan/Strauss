const express = require('express');

const app = express();

app.get('/', (req, res) => res.send('Hello World!'));

app.use('/users',require('./routes/users'));

app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

const port = process.env.PORT || 4555;

app.listen(port, () => console.log(`Example app listening on port ${port}!`));
