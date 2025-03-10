package hw02_OOP.hw02.case2;

public class extendsTest {
    public static void main(String args[]) {
        // 实例化一个Cat对象，设置属性name和age，调用voice()和eat()方法，再打印出名字和年龄信息
        /********* begin *********/
        Cat c = new Cat();
        c.setName("大花猫");
        c.setAge(6);
        c.voice();
        c.eat();
        c.info();
        /********* end *********/

        // 实例化一个Dog对象，设置属性name和age，调用voice()和eat()方法，再打印出名字和年龄信息
        /********* begin *********/
        Dog d = new Dog();
        d.setName("大黑狗");
        d.setAge(8);
        d.voice();
        d.eat();
        d.info();
        /********* end *********/

    }
}

class Animal {
    /********* begin *********/
    private String name;
    private int age;
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public Animal() {

    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void info(){
        System.out.println(name + age + "岁");
    }
    /********* end *********/

}

interface AnimalInterface {
    public void eat();
    public void voice();
}

class Cat extends Animal implements AnimalInterface {
    // 定义Cat类的voice()和eat()方法
    /********* begin *********/
    public Cat(String name, int age) {
        super(name, age);
    }
    public Cat() {

    }
    public void eat() {
        System.out.println(this.getName()+"吃鱼");
    }
    public void voice() {
        System.out.println(this.getName()+"喵喵叫");
    }
    /********* end *********/
}

class Dog extends Animal implements AnimalInterface {
    // 定义Dog类的voice()和eat()方法
    /********* begin *********/
    public Dog(String name, int age) {
        super(name, age);
    }
    public Dog(){

    }
    public void eat() {
        System.out.println(this.getName()+"吃骨头");
    }
    public void voice() {
        System.out.println(this.getName()+"汪汪叫");
    }
    /********* end *********/
}