package hw02_OOP.hw01;

class MyClass {
    static int i = 10;
    static {
        i = 20;
        System.out.println("In Static");
    }
    public MyClass() {
        System.out.println("MyClass()");
    }
    public MyClass(int i) {
        System.out.println("MyClass(int)");
        this.i = i;
    }
}
public class Test {
    public static void main(String args[]) {
        MyClass mc1 = new MyClass();
        System.out.println(mc1.i);
        MyClass mc2 = new MyClass(10);
        System.out.println(mc2.i);
    }
}