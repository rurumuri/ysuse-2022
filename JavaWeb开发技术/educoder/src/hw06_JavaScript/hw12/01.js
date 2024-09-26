function mainJs(a) {
    a = parseInt(a);
    //请在此处编写代码
    /********** Begin **********/

    var b = Math.ceil(a);
    var c = Math.floor(a);
    var d = Math.round(a);
    var e = Math.sqrt(a);
    var f = Math.sin(a);
    var vals = [a, b, c, d, e, f];

    return Math.max(...vals) + Math.min(...vals);

    /********** End **********/
}