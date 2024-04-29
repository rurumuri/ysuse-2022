package hw02_OOP.hw03.case1;

import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String dogName = sc.next();
        String dogSex = sc.next();
        String dogColor = sc.next();
        String catName = sc.next();
        String catSex = sc.next();
        double catWeight = sc.nextDouble();
        // 通过有参构造函数实例化Dog类对象dog
        // dog调用talk()方法
        // dog调用eat()方法
        /********* begin *********/
        Dog d = new Dog(dogName, dogSex, dogColor);
        d.talk();
        d.eat();
        /********* end *********/
        // 通过有参构造函数实例化Cat类对象cat
        // cat调用talk()方法
        // cat调用eat()方法
        /********* begin *********/
        Cat c = new Cat(catName, catSex, catWeight);
        c.talk();
        c.eat();
        /********* end *********/
    }
}

// 抽象类Pet 封装属性name和sex
// 构造函数初始化name和sex
// 声明抽象方法talk()
// 声明抽象方法eat()
abstract class Pet {
    /********* begin *********/
    private String name;
    private String sex;
    Pet(String name, String sex){
        this.name = name;
        this.sex = sex;
    }
    abstract void eat();
    abstract void talk();
    String getName(){
        return name;
    }
    String getSex(){
        return sex;
    }
    /********* end *********/
}

// Dog类继承自Pet类 封装属性color
// 构造函数初始化name、sex和color
// 实现自己的talk()方法和eat()方法
// talk()输出'名称：name，性别：sex，颜色：color，汪汪叫'
// eat()输出'name吃骨头'
class Dog extends Pet {
    /********* begin *********/
    private String color;
    Dog(String name, String sex, String color){
        super(name, sex);
        this.color = color;
    }
    void eat(){
        System.out.printf("%s吃骨头！\n", this.getName());
    }
    void talk(){
        System.out.printf("名称：%s，性别：%s，颜色：%s，汪汪叫\n", this.getName(), this.getSex(), this.color);
    }
    /********* end *********/
}

// Cat类继承自Pet类 封装属性weight
// 构造函数初始化name、sex和weight
// 实现自己的talk()方法和eat()方法
// talk()输出'名称：name，性别：sex，体重：weight kg，喵喵叫'
// eat()输出'name吃鱼'
class Cat extends Pet {
    /********* begin *********/
    private double weight;
    Cat(String name, String sex, double weight){
        super(name, sex);
        this.weight = weight;
    }
    void eat(){
        System.out.printf("%s吃鱼！\n", this.getName());
    }
    void talk(){
        System.out.printf("名称：%s，性别：%s，体重：%.1fkg，喵喵叫\n", this.getName(), this.getSex(), this.weight);
    }
    /********* end *********/
}