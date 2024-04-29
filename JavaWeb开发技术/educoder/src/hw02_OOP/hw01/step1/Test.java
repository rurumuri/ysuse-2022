package hw02_OOP.hw01.step1;

public class Test {
    public static void main(String[] args) {
        /********** Begin **********/
        //创建Dog对象
        Dog wuhuarou = new Dog();
        //设置Dog对象的属性
        wuhuarou.name = "五花肉";
        wuhuarou.color = "棕色";
        wuhuarou.variety = "阿拉斯加";

        //输出小狗的属性
        System.out.println("名字：" +  wuhuarou.name   + "，毛色：" +  wuhuarou.color  + "，品种：" + wuhuarou.variety );

        //调用方法
        wuhuarou.eat();
        wuhuarou.run();

        /********** End **********/

    }
}

//在这里定义Dog类
/********** Begin **********/
class Dog {
    String name;
    String color;
    String variety;
    public Dog(){
        this.name = "";
        this.color = "";
        this.variety = "";
    }
    public Dog(String name, String color, String variety) {
        this.name = name;
        this.color = color;
        this.variety = variety;
    }
    public void eat(){
        System.out.println("啃骨头");
    }
    public void run(){
        System.out.println("叼着骨头跑");
    }
}


/********** End **********/
