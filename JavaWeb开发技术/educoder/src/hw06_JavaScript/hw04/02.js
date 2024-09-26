var store = {
    name:"Luma Restaurant",
    location:"No 22,Cot Road",
    accountant:"Vivian Xie",
    day1:3200,
    day2:3200,
    day3:3200,
    day4:3200,
    day5:3200,
    day6:3200,
    day7:3200,
    day8:3200,
    day9:3200,
    day10:3200
}
function reviseAttribute(reviser,date,attValue) {
    //Convert string to integer
    attValue = parseInt(attValue);
    //请在此处编写代码
    /*********begin*********/
    store.accountant = reviser;
    store["day" + date] = attValue;

    /*********end*********/
    var totalSales =  store["day1"]+store["day2"]+store["day3"]+store["day4"]+store["day5"]+store["day6"]+store["day7"]+store["day8"]+store["day9"]+store["day10"];
    return totalSales+store.accountant;
}