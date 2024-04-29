package hw02_OOP.hw01.step3;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        int age = sc.nextInt();
        String sex = sc.next();
        Person p = new Person(name,age,sex);
        p.display();
    }
}

class Person{
    String name;
    int age;
    String sex;
    /********** Begin **********/

    public Person(String name,int age,String sex){
        this(age);
        this.name = name;
        this.sex = sex;
    }

    public Person(int age){
        this.age = age;
    }

    public void display(){
        String name = this.name;
        int age = this.age;
        String sex = this.sex;
        System.out.println("name：" + name);
        System.out.println("age：" + age);
        System.out.println("sex：" + sex);
    }


    /********** End **********/
}
