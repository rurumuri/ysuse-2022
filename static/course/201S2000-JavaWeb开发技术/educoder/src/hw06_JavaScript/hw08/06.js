var park = {
    name:"Leaf Prak",
    location:"Fifth Avenue",
    todayTourists:4000
};

var computer = {
    name:"Levenon",
    price:"$800",
    memory:"8G"
};

var city = {
    name:"HangZhou",
    country:"Chine",
    population:9400000
}

function objectFunction(object) {
//请在此处编写代码
    /********** Begin **********/
    var res = "";
    for(att in object) {
        res += (att+":"+object[att]+",");
    }
    return res;

    /********** End **********/
}

function mainJs(a) {
    a = parseInt(a);
    switch(a) {
        case 1:return objectFunction(park);
        case 2:return objectFunction(computer);
        case 3:return objectFunction(city);
        default:break;
    }
}