//请在此处编写代码
/********** Begin **********/
function getMax() {
    if(arguments.length === 0) {
        return 0;
    }

    var res = arguments[0];
    for (var i of arguments) {
        if (i >= res) {
            res = i;
        }
    }
    return res;
}

/********** End **********/

function mainJs(a) {
    a = parseInt(a);
    switch(a) {
        case 1:return getMax(23,21,56,34,89,34,32,11,66,3,9,55,123);
        case 2:return getMax(23,21,56,34,89,34,32);
        case 3:return getMax(23,21,56,34);
        case 4:return getMax(23,21,56,34,89,34,32,11,66,3,9,55,123,8888);
        case 5:return getMax();
        default:break;
    }
}

// console.log(mainJs(5))