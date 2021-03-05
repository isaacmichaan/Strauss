var bcrypt = require('bcryptjs');

const Sequelize = require('sequelize');

// initialze an instance of Sequelize
const sequelize = new Sequelize({
  dialect: 'sqlite',
  storage: 'mydb.sqlite',
  operatorsAliases: 0
});

// check the databse connection
sequelize
    .authenticate()
    .then(() => console.log(''))
    .catch(err => console.error('Unable to connect to the database:', err));

// create user model
const UserSchema = sequelize.define('user', {
  username: {
    type: Sequelize.STRING,
  },
  password: {
    type: Sequelize.STRING,
  },
});

// create table with user model
UserSchema.sync()
    .then(() => console.log(''))
    .catch(err => console.log('oooh, did you enter wrong database credentials?'));

module.exports = UserSchema;

module.exports.createUser = function(newUser, callback){
  bcrypt.genSalt(10, function(err, salt){
    bcrypt.hash(newUser.password, salt, function(err, hash){
      newUser.password = hash;
      newUser.save(callback);
    });
  });
};

module.exports.getUserByUsername = (username) => {
  return new Promise(async (resolve, reject) =>{
    let exists = await UserSchema.findOne({
      where: {
        username: username
      }
    });
    resolve (exists);
  });
};

module.exports.getUserById = (id, callback) => {
  return new Promise(async (resolve, reject) =>{
    let exists = await UserSchema.findOne({
      where: {
        id: id
      }
    });
    resolve (exists);
  });
};

module.exports.comparePassword = (candidatePassword, hash) => {
  return new Promise(async (resolve, reject) => {
    await bcrypt.compare(candidatePassword, hash, (err, isMatch) => {
      if(err) throw err;
      resolve(isMatch);
    });
  });
};
