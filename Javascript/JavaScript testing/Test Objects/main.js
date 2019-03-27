/**
 * Created with JetBrains WebStorm.
 * User: zvanjak
 * Date: 30.06.13.
 * Time: 10:43
 * To change this template use File | Settings | File Templates.
 */

function Ninja(){}
Ninja.prototype.swingSword = function(){
    return true;
};

var ninja1 = Ninja();
assert(ninja1 === undefined,
    "No instance of Ninja created.");

var ninja2 = new Ninja();
assert(ninja2 &&
    ninja2.swingSword &&
    ninja2.swingSword(),
    "Instance exists and method is callable." );