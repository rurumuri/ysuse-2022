package hw02_OOP.hw02.case4;

public class overridingTest {
    public static void main(String[] args) {
        // 实例化子类对象s，调用talk()方法打印信息
        /********* begin *********/
        Student s = new Student("张三", 18, "哈佛大学");
        s.talk();
        /********* end *********/

    }
}

class Person {
    /********* begin *********/
    String name;
    int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public void talk(){
        System.out.printf("我是：%s，今年：%d岁\n", name, age);
    }
    /********* end *********/
}

class Student extends Person {
    /********* begin *********/
    String school;
    public Student(String name, int age, String school) {
        super(name, age);
        this.school = school;
    }
    @Override
    public void talk(){
        System.out.printf("我是：%s，今年：%d岁，我在%s上学\n", name, age, school);
    }
    /********* end *********/
}