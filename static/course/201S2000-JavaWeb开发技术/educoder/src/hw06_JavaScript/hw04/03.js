var orange = {
    weight:"200g",
    color:"orange",
    taste:"sour"
};
var car = {
    brand:"Jaguar",
    price:"$80000",
    model:"XFL"
}
function mainJs(a){
    //请在此处编写代码
    /*********begin*********/
    var obj = orange.hasOwnProperty(a) ? orange : car.hasOwnProperty(a) ? car : null;
    if (obj === null) {
        return "The property does not belong to any of the objects.";
    }
    return Object.keys(obj).join('');

    /*********end*********/
}
