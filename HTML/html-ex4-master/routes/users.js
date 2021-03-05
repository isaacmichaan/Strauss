var express= require('express');
var router = express.Router();
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;

var User = require('../models/user');

//Register
router.get('/register', function(req,res){
  res.render('register');
});

//login
router.get('/login', function(req,res){
  res.render('login');
});

//Register User
router.post('/register', function(req,res){
var name = req.body.name;
var email = req.body.email;
var username = req.body.username;
var password = req.body.password;
var password2 = req.body.password2;

//validation
req.checkBody('name', 'Name is required').notEmpty();
req.checkBody('email', 'email is required').notEmpty();
req.checkBody('username', 'username is required').notEmpty();
req.checkBody('password', 'password is required').notEmpty();
req.checkBody('password2', 'passwords do not match').equals(req.body.password);

var errors = req.validationErrors();

if(errors){
  console.log(errors)
res.render('register', {
  error:errors
});
} else {
var newUser = new User({
  name:name,
  email:email,
  username:username,
  password:password
});
User.createUser(newUser, function(err,user){
  if(err) throw err;
  console.log(user);
});
req.flash('success_msg','You are registered and can now log in.');
res.redirect('/users/login');
}
});

passport.use(new LocalStrategy(
  function(username, password, done){
    User.getUserByUsername(username).then((user) => {
      console.log(user);
      // if(err) throw err;
      if(!user){
        return done(null, false, {message:"Unknown user"});
      }
      User.comparePassword(password, user.password).then((isMatch) =>{
        // if(err) throw err;
        if(isMatch){
          return done(null, user);
        } else {
          return done(null, false, {message:'Invalid password'});
        }
      });
    });
  }));

  passport.serializeUser(function(user, done){
    done(null, user.id);
  });

  passport.deserializeUser(function(id, done){
    User.getUserById(id).then((user) => {
      done(null, user);
    });
  });

router.post('/login', passport.authenticate('local', {successRedirect:'/', failureRedirect:'/users/login', failureFlash: true}), function(req,res){
  // console.log("YeP");
  res.redirect('/');
});

router.get('/logout', function(req,res){
  req.logout();
  req.flash('success', 'logout successfull');
  res.redirect('/users/login');
});
module.exports = router;
