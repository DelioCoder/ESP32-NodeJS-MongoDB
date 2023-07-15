const dataCtrl = {};

const Data = require('../model/data');

dataCtrl.getData = async(req, res) => {

    const data = await Data.find();

    if(data){
        res.status(200).json(data);
    }

}

dataCtrl.sendData = async(req, res) => {
    // console.log(`Temperatura: ${req.query.Temperatura}`);
    // console.log(`Humedad: ${req.query.Humedad}`);
    // res.sendStatus(200);
    try {
        
        const { Temperatura, Humedad } = req.query;
        console.log(`${Temperatura} y ${Humedad}` );

        const newData = new Data({
            temperatura: Temperatura,
            humedad: Humedad
        });

        await newData.save();

        if(newData){
        
            res.sendStatus(200);
        }

    } catch (error) {
        res.json(error);
    }
}

module.exports = dataCtrl;