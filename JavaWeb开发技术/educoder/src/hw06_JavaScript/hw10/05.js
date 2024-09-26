function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/

    var pattern1 = /(\?\+){2,}/
    var pattern2 = /[0-9]([?+])[0-9]/

    /********** End **********/
    return pattern1.test(a).toString()+","+pattern2.test(a).toString();
}