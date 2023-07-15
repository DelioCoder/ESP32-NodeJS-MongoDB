const express = require('express');
const cors = require('cors');
const morgan = require('morgan');
const app = express();

app.set('port', 4000);

app.use(cors());
app.use(express.json());
app.use(morgan('dev'));

// Routes
app.use('/api/data', require('./routes/dataRoute'));

module.exports = app;