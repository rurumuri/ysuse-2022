function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/
    var pattern1 = /[a-zA-Z][0-9]/;
    var pattern2 = /A[^0-9]/;

    /********** End **********/
    return pattern1.test(a).toString()+","+pattern2.test(a).toString();
}