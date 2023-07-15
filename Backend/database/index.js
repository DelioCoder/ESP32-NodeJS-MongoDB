const mongoose = require('mongoose');

const URI = process.env.MONGODB_URL
    ? process.env.MONGODB_URL
    : 'mongodb://localhost/';

mongoose.connect(URI);

const connection = mongoose.connection;

//Una vez que se conecte a nuestra BD, que nos mande un mensaje en consola

connection.once('open', () =>{
    console.log('DB is connected');
});