function mainJs(a,b,c,d) {
    //请在此处编写代码
    /********** Begin **********/
    if (a === undefined) {
        a = "green";
    }
    if (b === undefined) {
        b = "green";
    }
    if (c === undefined) {
        c = "red";
    }
    if (d === undefined) {
        d = "yellow";
    }

    return a.concat("-", b).concat("-", c).concat("-", d);

    /********** End **********/
}
