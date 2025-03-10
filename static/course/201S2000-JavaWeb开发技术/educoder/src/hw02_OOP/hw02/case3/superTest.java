package hw02_OOP.hw02.case3;

public class superTest {
    public static void main(String[] args) {
        // 实例化一个Student类的对象s，为Student对象s中的school赋值，打印输出信息
        /********* begin *********/
        Student s = new Student("张三", 18, "哈佛大学");
        s.info();
        /********* end *********/
    }
}

class Person {
    /********* begin *********/
    String name;
    int age;
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    /********* end *********/
}

class Student extends Person {
    /********* begin *********/
    String school;
    Student(String name, int age, String school) {
        super(name, age);
        this.school = school;
    }
    void info(){
        System.out.println("姓名："+this.name+"，年龄："+this.age+"，学校："+this.school);
    }
    /********* end *********/
}
