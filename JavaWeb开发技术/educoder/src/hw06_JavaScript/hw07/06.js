function mainJs(a,b) {
    a = a.split(",");
    for(var i = 0,length = a.length;i < length;i++) {
        a[i] = parseInt(a[i]);
    }
    var sum = 0;
    for(var i = 0,length = a.length;i < length;i++) {
        //请在此处编写代码
        /********** Begin **********/
        if(a[i] * b < 0){
            continue;
        }
        /********** End **********/
        sum += a[i];
    }
    return sum;
}