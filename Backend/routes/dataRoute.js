const { Router } = require('express');

const router = Router();

const { sendData, getData } = require('../controllers/dataController');

router.route('/')
    .get(getData)
    .post(sendData);

module.exports = router;