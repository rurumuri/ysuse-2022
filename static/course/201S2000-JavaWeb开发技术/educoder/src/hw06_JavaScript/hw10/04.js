function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/

    var pattern1 = /[0-9]{17}([0-9]|X)/
    var pattern2 = /(23|24)[0-9]{4}/
    var pattern3 = /010|02([0-5]|[7-9])/

    /********** End **********/
    return pattern1.test(a).toString()+","+pattern2.test(a).toString()+","+pattern3.test(a).toString();
}