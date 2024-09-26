var testArray = [12,"java","js","c","c++",24,36,"python","c#","css"];
function mainJs(a,b) {
    a = parseInt(a);
    b = parseInt(b);
    //请在此处编写代码
    /*********begin*********/
    while (a--) {
        var c = testArray[testArray.length - 1];
        testArray.length--;
        testArray.unshift(c);
    }
    return testArray[b];

    /*********end*********/
}