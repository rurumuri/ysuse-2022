package hw02_OOP.hw02.case5;

public class abstractTest {
    public static void main(String[] args) {
        /********* begin *********/
        // 分别实例化Student类与Worker类的对象，并调用各自构造方法初始化类属性。
        Student s = new Student("张三", 20, "学生");
        Worker w = new Worker("李四", 30, "工人");
        // 分别调用各自类中被复写的talk()方法 打印信息。
        s.talk();
        w.talk();
        /********* end *********/

    }
}

// 声明一个名为Person的抽象类，在Person中声明了三个属性name age occupation和一个抽象方法——talk()。
abstract class Person {
    /********* begin *********/
    String name;
    int age;
    String occupation;
    abstract void talk();
    /********* end *********/
}

// Student类继承自Person类，添加带三个参数的构造方法，复写talk()方法 返回姓名、年龄和职业信息
class Student extends Person {
    /********* begin *********/
    Student(String name, int age, String occupation) {
        this.name = name;
        this.age = age;
        this.occupation = occupation;
    }
    void talk() {
        System.out.printf("学生——>姓名：%s，年龄：%d，职业：%s！\n", name, age, occupation);
    }
    /********* end *********/
}

// Worker类继承自Person类，添加带三个参数的构造方法，复写talk()方法 返回姓名、年龄和职业信息
class Worker extends Person {
    /********* begin *********/
    Worker(String name, int age, String occupation) {
        this.name = name;
        this.age = age;
        this.occupation = occupation;
    }
    void talk() {
        System.out.printf("工人——>姓名：%s，年龄：%d，职业：%s！\n", name, age, occupation);
    }
    /********* end *********/

}