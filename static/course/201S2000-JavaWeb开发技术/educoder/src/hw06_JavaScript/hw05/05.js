function mainJs(a) {
    var arr = a.split(",");
    for(var i = 0;i < arr.length;i++) {
        arr[i] = parseInt(arr[i]);
    }
    var result = [];
    var aLength = arr.length;
    for(var i = 0;i < aLength-1;i++) {
        var max = arr[0];
        var maxIndex = 0;
        for(var j = 1;j < aLength-i;j++) {
            if(arr[j] > max) {
                max = arr[j];
                maxIndex = j;
            }
        }
        result.push(maxIndex);
        //将本次选出的最大元素移动到最终的位置上
        var temp = arr[aLength-i-1];
        arr[aLength-i-1] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
    return result;
}
