var arr = [1,2,3,4,5,6,7,8,9,0,10,11,12,13,14,15,16,17,18,19,20,21,23,22];
function mainJs(a,b) {
    a = parseInt(a);
    b = parseInt(b);
    //请在此处编写代码
    /*********begin*********/
    var newarr = new Array(a);
    for (var i = 0; i < a; i++) {
        var subarr = new Array(b);
        for (var j = 0; j < b; j++){
            if (b * i + j < arr.length) subarr[j] = arr[b * i + j];
        }
        newarr[i] = subarr;
    }
    return newarr;

    /*********end*********/
}
