const express = require('express');
const cors = require('cors');
const morgan = require('morgan');
const app = express();

app.set('port', 4000);

app.use(cors());
app.use(express.json());
app.use(morgan('dev'));

// Routes
app.post('/api/data', (req, res) => {

    console.log(req.body);
    console.log(`Query: ${req.query.Temperatura}`);
    res.sendStatus(200);
});
  

module.exports = app;