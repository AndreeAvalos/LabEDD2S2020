const express = require('express');
const bodyParser = require('body-parser');
let app = express();

app.use(bodyParser.urlencoded({ extended: true, parameterLimit: 50000 }));
app.use(bodyParser.json({ limit: '5000mb', extended: true }));

app.use('/', require('./controller/homeController'));


module.exports = app
