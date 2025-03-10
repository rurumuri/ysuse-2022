package hw02_OOP.hw02.case8;

public class TestPolymorphism {
    public static void main(String[] args) {
        // 以多态方式分别实例化子类对象并调用eat()方法
        /********* begin *********/
        Animal a = new Dog();
        a.eat();
        Animal b = new Cat();
        b.eat();
        Animal c = new Lion();
        c.eat();
        /********* end *********/
    }
}

// Animal类中定义eat()方法
class Animal {
    /********* begin *********/
    Animal(){

    }
    void eat(){

    }
    /********* end *********/
}

// Dog类继承Animal类 复写eat()方法
class Dog extends Animal {
    /********* begin *********/
    Dog(){

    }
    @Override
    void eat(){
        System.out.println("eating bread...");
    }
    /********* end *********/
}

// Cat类继承Animal类 复写eat()方法
class Cat extends Animal {
    /********* begin *********/
    Cat(){

    }
    @Override
    void eat(){
        System.out.println("eating rat...");
    }
    /********* end *********/
}

// Lion类继承Animal类 复写eat()方法
class Lion extends Animal {
    /********* begin *********/
    Lion(){

    }
    @Override
    void eat(){
        System.out.println("eating meat...");
    }
    /********* end *********/
}
