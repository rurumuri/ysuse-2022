var apple = {
    weight:"200克",
    level:"特级",
    locationProvince:"陕西省",
    locationCity:"榆林市"
}
function mainJs(a,b){
    apple[a]= b;
    //请在此处编写代码
    /********** Begin **********/
    res = "";
    for (var ap in apple) {
        if(ap.indexOf("location") !== -1) {
            res += apple[ap];
        }
    }

    return res;
    /********** End **********/
}

//console.log(mainJs("locationTest", "Ahaha"));