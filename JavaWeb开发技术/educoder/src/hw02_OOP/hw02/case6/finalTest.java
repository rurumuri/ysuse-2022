package hw02_OOP.hw02.case6;

public class finalTest {
    public static void main(String args[]) {
        Bike1 obj = new Bike1();
        obj.run();

        Honda honda = new Honda();
        honda.run();

        Yamaha yamaha = new Yamaha();
        yamaha.run();
    }
}
//不可以修改 final 变量的值
// final方法,不可以重写
//// 不可以扩展 final 类
//请在此添加你的代码
/********** Begin *********/
class Bike1 {
    int speedlimit = 90;
    void run() {
        speedlimit = 120;
        System.out.println("speedlimit=120");
    }

}

class Bike2 {
    void run() {
        System.out.println("running");
    }
}

class Honda extends Bike2 {
    void run() {
        System.out.println("running safely with 100kmph");
    }

}

class Bike3 {
}

class Yamaha extends Bike3 {
    void run() {
        System.out.println("running safely with 100kmph");
    }

}
/********** End **********/
