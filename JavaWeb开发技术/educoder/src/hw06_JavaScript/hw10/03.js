function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/

    var pattern1 = /\?{1,}]/
    var pattern2 = /\+{3}/
    var pattern3 = /(\{}){1,2}/
    var pattern4 = /\\*/

    /********** End **********/
    return pattern1.test(a).toString()+","+pattern2.test(a).toString()+","+pattern3.test(a).toString()+","+pattern4.test(a).toString();
}