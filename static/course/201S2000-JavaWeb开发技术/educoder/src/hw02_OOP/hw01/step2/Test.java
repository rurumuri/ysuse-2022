package hw02_OOP.hw01.step2;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        String sex = sc.next();
        /********** Begin **********/
        //分别使用两种构造器来创建Person对象
        Person p1 = new Person();
        Person p2 = new Person(name, sex);
        /********** End **********/

    }
}

//创建Person对象，并创建两种构造方法
/********** Begin **********/
class Person {
    String name;
    String sex;
    public Person() {
        System.out.println("一个人被创建了");
    }
    public Person(String name, String sex){
        this.name = name;
        this.sex = sex;
        System.out.println("姓名："+name+"，性别："+sex+"，被创建了");
    }
}


/********** End **********/
