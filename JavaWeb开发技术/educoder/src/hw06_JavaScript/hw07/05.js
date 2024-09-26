function mainJs(a) {
    var arr = a.split(",");
    for(var k = 0,length = arr.length;k < length;k++) {
        arr[k] = parseInt(arr[k]);
    }
    //请在此处编写代码
    /********** Begin **********/
    var temp=0;
    var zhishu=1;
    for(var i=0;i<arr.length;i++)
    {
        temp=arr[i];
        if(temp==2)
        {
            return "2";
        }
        else if(temp>2)
        {
            for(var j=2;j<=temp**0.5;j++)
            {
                if(temp%j==0)
                {
                    zhishu=0;
                    break;
                }
            }
            if(zhishu==1)
            {
                return temp;
            }
            zhishu=1;
        }
    }

    /********** End **********/
}

console.log(mainJs("1,1,1,4,1"));