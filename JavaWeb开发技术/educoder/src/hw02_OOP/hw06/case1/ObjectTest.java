package hw02_OOP.hw06.case1;

import java.util.Scanner;

public class ObjectTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        // 在测试类中创建Demo类对象d1，传入输入值num1， d1调用toString方法并打印输出该值
        // 创建Demo类对象d2，同样传入输入值num1，打印判断d1和d2是否相等（实际是比较地址）
        /********* Begin *********/
        Demo d1 = new Demo(num1);
        System.out.println(d1.toString());
        Demo d2 = new Demo(num1);
        System.out.println(d1.equals(d2));
        /********* End *********/
        // 创建Person类对象p，传入输入值num2，打印判断d1和p是否相等（实际是比较地址）
        /********* Begin *********/
        Person p = new Person(num2);
        System.out.println(d1.equals(p));
        /********* End *********/
    }
}

class Demo {
    private int num;

    public Demo(int num) {
        this.num = num;
    }

    public boolean equals(Object obj) // Object obj = new Demo()
    {
        if (!(obj instanceof Demo)) // 判断obj是否和Demo是同类
            return false;
        Demo d = (Demo) obj; // 将父类的引用(Object)向下转换为子类(Demo)
        return this.num == d.num;
    }

    public String toString() {
        return "Demo:" + num; // 返回对象的值（每一个对象都有自己的特定的字符串）
    }
}

class Person {
    private int num;

    public Person(int num) {
        this.num = num;
    }
}