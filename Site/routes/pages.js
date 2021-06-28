const express = require('express');
const authController = require('../controllers/auth');

const router = express.Router();

router.get('/',authController.isLoggedIn, (req, res) =>{
    res.render('index', {
        users: req.users
    });
});

router.get('/register', (req, res) =>{
    res.render('register');
});

router.get('/login', (req, res) =>{
    res.render('login');
});

router.get('/contact', (req, res) =>{
    res.render('contact');
});

router.get('/about', (req, res) =>{
    res.render('about');
});

router.get('/app', (req, res) =>{
    res.render('app');
});

router.get('/subscribe', (req, res) =>{
    res.render('subscribe');
});

router.get('/feedback', (req, res) =>{
    res.render('feedback');
});

router.get('/extraPage', (req, res) =>{
    res.render('extraPage');
});

module.exports = router;