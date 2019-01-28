var exec = require('cordova/exec');


var _module = "woosimPrint";


exports.connect = function(success, error) {
    exec(success, error, _module, 'connect')
};

exports.printString = function(success, error, arg0) {
    exec(success, error, _module, 'printString', [arg0]);
}