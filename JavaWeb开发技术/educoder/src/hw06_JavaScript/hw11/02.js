var myJson = {
    "category":"computer",
    "detail":"programming",
    "language":[
        "js","java","php","python","c"
    ]
}
function mainJs(a) {
    a = parseInt(a);
    //请在此处编写代码
    /********** Begin **********/
    var res = "";
    var s = false;
    for(var i = 0; i < a; i++) {
        if(s) res += ",";
        else s = true;
        res += myJson.language[i];
    }
    return res;
    /********** End **********/
}