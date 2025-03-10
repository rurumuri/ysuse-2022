//求数组中奇数元素的个数
function getOddNumber(a) {
    var result = 0;
    for(var i = 0;i < a.length;i++) {
        if(a[i]%2 != 0)
            result++;
    }
    return result;
}

//求数组中偶数元素的个数
function getEvenNumber(a) {
    var result = 0;
    for(var i = 0;i < a.length;i++) {
        if(a[i]%2 == 0)
            result++;
    }
    return result;
}

function getNumber(func,a) {
    //请在此处编写代码
    /********** Begin **********/
    return func(a);

    /********** End **********/
}

//测试接口
function mainJs(b,a) {
    a = a.split(",");
    var aLength = a.length;
    for(var i = 0;i < aLength;i++) {
        a[i] = parseInt(a[i]);
    }
    if(b == "getEvenNumber") {
        return getNumber(getEvenNumber,a);
    } else {
        return getNumber(getOddNumber,a);
    }
}