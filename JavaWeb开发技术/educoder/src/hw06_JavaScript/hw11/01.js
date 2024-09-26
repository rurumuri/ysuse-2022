function mainJs(a,b,c) {
    //请在此处编写代码
    /********** Begin **********/

    var res = "";

    var JSONObject = {
        "key1": a,
        "key2": b,
        "key3": c,
    }

    delete JSONObject.key3;

    var x = false;
    for (var att in JSONObject) {
        if(x){
            res += ",";
        } else {
            x = true;
        }
        res += JSONObject[att];
    }

    return res;
    /********** End **********/
}