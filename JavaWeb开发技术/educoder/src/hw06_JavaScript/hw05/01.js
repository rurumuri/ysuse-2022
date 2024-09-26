var array1 = [1,2,3,"js",4,true,"hello"];
var array2 = [true,true,"java",2.1];
function mainJs(a) {
    //请在此处编写代码
    /*********begin*********/
    if (array1.length == a) {
        return array1[array1.length - 1];
    } else {
        return array2[array2.length - 1];
    }

    /*********end*********/
}