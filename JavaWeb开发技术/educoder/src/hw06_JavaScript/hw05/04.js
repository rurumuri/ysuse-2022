function mainJs(myArray) {
    myArray = myArray.split(",");
    //请在此处编写代码
    /*********begin*********/
    var res = new Array();
    var idx = myArray.indexOf('a', 0);
    while (idx != -1) {
        res.push(idx);
        idx = myArray.indexOf('a', idx+1);
    }

    var idx = myArray.indexOf('b', 0);
    while (idx != -1) {
        res.push(idx);
        idx = myArray.indexOf('b', idx+1);
    }
    return res;
    /*********end*********/
}
