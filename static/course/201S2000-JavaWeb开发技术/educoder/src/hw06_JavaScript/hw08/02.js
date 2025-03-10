function mainJs(a) {
    a = parseInt(a);
    //请在此处编写代码
    /********** Begin **********/
    var myFunc = function (x) {
        return parseInt(x / 100 % 10) + parseInt(x / 10 % 10) + parseInt(x % 10);
    }
    /********** End **********/
    return myFunc(a);
}