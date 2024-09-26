function mainJs(a,b) {
    //请在此处编写代码
    /********** Begin **********/
    var curpos = 0;
    var res = 0;

    while(true) {
        curpos = a.indexOf(b, curpos);
        if (curpos === -1) {
            break;
        } else {
            res += curpos;
            curpos += b.length;
        }
    }

    return res;

    /********** End **********/
}

console.log(mainJs("ababab","ab"));