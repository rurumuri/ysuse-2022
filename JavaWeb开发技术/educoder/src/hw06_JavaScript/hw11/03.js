var JSONString = '{"key1":"value1","key2":"value2"}';
function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/

    var JSONObject = JSON.parse(JSONString);
    JSONObject.key1 = a;
    return JSON.stringify(JSONObject);

    /********** End **********/
}