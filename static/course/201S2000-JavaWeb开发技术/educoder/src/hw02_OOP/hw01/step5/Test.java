package hw02_OOP.hw01.step5;

public class Test {
    /********** Begin **********/
    static String name = "楚留香";

    static {
        System.out.println("hello educoder");
    }
    public static void main(String[] args) {
        System.out.println("我叫" + name);
        study();
    }

    public static void study(){
        System.out.println("我喜欢在educoder上学习java");
    }
    /********** End **********/
}
