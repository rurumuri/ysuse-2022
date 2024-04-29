package hw02_OOP.hw09.step1;

//编写一个Cube类继承Rectangle
public class Cube extends Rectangle{
    /*********begin*********/
    //创建两个构造函数
    //创建 无参 构造函数  调用父类构造方法默认 宽高 都为10
    Cube(){
        super(10, 10);
    }

    //创建 有参 构造函数 参数为 double d
    Cube(double d){
        super(d,d);
    }
    //调用父类中的area方法和perimeter方法
    public double area(){
        return super.area();
    }
    public double perimeter(){
        return super.perimeter();
    }

    //编写计算体积的方法
    public double vol(){
        return Math.pow(this.getWidth(), 3);
    }

    public static void main(String[] args){
        //创建两个正方体实例对象，并按相应格式输出正方体的底面周长，底面面积和体积。
        //创建一个 无参 正方体对象
        Cube c = new Cube();
        System.out.println("c底面周长："+ c.perimeter()  );
        System.out.println("c底面面积："+ c.area()  );
        System.out.println("c体积："+  c.vol()    );


        //创建一个 有参 正方体对象 参数值为： 5
        Cube c1 = new Cube(5);
        System.out.println("c1底面周长："+ c1.perimeter()  );
        System.out.println("c1底面面积："+ c1.area() );
        System.out.println("c1体积："+  c1.vol()    );

        /*********end*********/

    }
}