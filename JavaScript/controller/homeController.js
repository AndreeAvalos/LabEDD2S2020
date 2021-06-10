var router = require('express').Router();
const listaService = require('../service/listaService');

router.get('/home', (req, res) => {
    res.send("<title>Estructuras de Datos</title>");
});

router.post('/insert', (req, res) => {
    listaService.add(req.body)
        .then(response => res.json(response));
});

router.get('/print', (req, res) => {
    listaService.print()
        .then(response => res.json(response));
});

module.exports = router;
