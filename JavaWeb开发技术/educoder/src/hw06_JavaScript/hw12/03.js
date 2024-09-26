function mainJs(a) {
    //请在此处编写代码
    /********** Begin **********/

    try {
        if(a < 0){
            throw new Error("negative cannot be rooted");
        } else if(a == 0){
            throw new Error("zero cannot be numerator");
        }
        return 1/Math.sqrt(a);
    } catch(e) {
        return e.message;
    }

    /********** End **********/
}

console.log(mainJs(0));