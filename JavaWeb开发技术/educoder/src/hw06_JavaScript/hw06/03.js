//判断一个年份是否为闰年
function judgeLeapYear(year) {
    //请在此处编写代码
    /********** Begin **********/
    var res = true;
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            res = true;
        } else {
            res = false;
        }
    } else {
        if (year % 4 == 0) {
            res = true;
        } else {
            res = false;
        }
    }
    if (res) return year + "年是闰年";
    else return year + "年不是闰年";
    /********** End **********/
}

//对输入进行规范化处理
function normalizeInput(input) {
    /********** Begin **********/
    switch (input) {
        case "中共党员":
        case "党员":
        case "共产党员":
            return "中共党员";
        case "中共预备党员":
        case "预备党员":
            return "中共预备党员";
        case "团员":
        case "共青团员":
            return "共青团员";
        case "大众":
        case "群众":
        case "市民":
        case "人民":
            return "群众";
        default:
            return "错误数据";
    }
    /********** End **********/
}

//判断苹果是否为优质品
function evaluateApple(weight,water) {
    /********** Begin **********/
    if (weight >= 200) {
        return "是优质品";
    } else if (water >= 0.7) {
        return "是优质品";
    }
    return "不是优质品"
    /********** End **********/
}