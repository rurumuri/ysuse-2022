package hw02_OOP.hw09.step2;

public class Circle extends Point {
    private double radius;

    /*********begin*********/
    //编写两个构造方法，无参函数中的半径默认为10，x和y均为0;
    //在构造方法中输出Circle constructor:  加上 toString方法输出的结果
    Circle() {
        super(0, 0);
        this.radius = 10;
        System.out.println("Circle constructor:"+this.toString());
    }

    Circle(double r, double x, double y) {
        super(x, y);
        this.radius = r;
        System.out.println("Circle constructor:"+this.toString());
    }

    //编写toString方法
    public String toString(){
        return "Center="+super.toString()+"radius="+this.radius;
    }
    /*********end*********/

    public static void main(String[] args) {
        Circle cir1, cir2;

        System.out.println("第一个圆的信息：");
        /*********begin*********/
        //构造第一个圆cir1
        cir1 = new Circle();



        System.out.println("第二个圆的信息：");
        //构造第二个圆cir2，x为10，y为10，半径为5
        cir2 = new Circle(5, 10, 10);
        /*********end*********/

    }
}
