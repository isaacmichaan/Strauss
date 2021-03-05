var bcrypt = require('bcryptjs');

const Sequelize = require('sequelize');

// initialze an instance of Sequelize
const sequelize = new Sequelize({
    dialect: 'sqlite',
    storage: 'mydb.sqlite3',
    operatorsAliases: 0
});

// check the databse connection
sequelize
    .authenticate()
    .then(() => console.log(''))
    .catch(err => console.error('Unable to connect to the database:', err));

// create user model
const User = sequelize.define('user', {
    name: {
        type: Sequelize.STRING,
        unique: true
    },
});

// create table with user model
User.sync()
    .then(() => console.log(''))
    .catch(err => console.log('oooh, did you enter wrong database credentials?'));

module.exports = User;

module.exports.createUser = function(newUser){
    User.create({name: newUser});
};

module.exports.getUserByName = (name) => {
    return new Promise(async (resolve, reject) =>{
        let exists = await User.findOne({
            where: {
                name: name
            }
        });
        if (exists)
            return resolve (true);
        return resolve (false)
    });
};

module.exports.getAllUsers = () => {
    return new Promise(async (resolve, reject) =>{
        User.findAll().then(function (users) {
            return resolve(users);
        }).catch(function(err) {
            console.log(err);
        });
    });
};

module.exports.deleteUserByName = async (name) => {
        await User.destroy({
            where: {
                name: name
            }
        });
};
