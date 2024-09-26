//求最大值的函数
function getMax(b,c) {
    return b>c?b:c;
}

//求最小值的函数
var getMin = function(b,c) {
    return b>c?c:b;
}

//对象中的求和函数
var myObject = {
    id:1,
    name:"function",
    myFunc:function(b,c) {
        return b+c;
    }
}

function mainJs(a,b,c) {
    a = parseInt(a);
    b = parseInt(b);
    c = parseInt(c);
    //请在此处编写代码
    /********** Begin **********/
    switch(a) {
        case 1: {
            return getMax(b,c);
        }
        case 2: {
            return getMin(b,c);
        }
        case 3: {
            return myObject.myFunc(b,c);
        }
    }
    /********** End **********/
}