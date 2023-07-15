const { Schema, model } = require('mongoose');

const dataSchema = new Schema({
   temperatura : Number,
   humedad: Number
},{
    timestamps: true
});

var dataModel = model('datas', dataSchema);

module.exports = model('Datas', dataSchema);