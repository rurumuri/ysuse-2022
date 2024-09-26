function mainJs(a,b) {
    //请在此处编写代码
    /********** Begin **********/
    var res = "";
    for(var c of a) {
        if ("ATGCU".indexOf(c) !== -1) {
            res += c;
        }
    }

    return res;

    /********** End **********/
}