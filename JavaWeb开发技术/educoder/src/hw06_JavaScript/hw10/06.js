function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/

    var pattern1 = /([0-9]{3})[^0-9]\1/
    var pattern2 = /([A-Z])([0-9])[A-Z]\2[A-Z]\2/

    /********** End **********/
    return pattern1.test(a).toString()+","+pattern2.test(a).toString();
}