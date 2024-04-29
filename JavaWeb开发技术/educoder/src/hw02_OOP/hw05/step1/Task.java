package hw02_OOP.hw05.step1;

public class Task {
    public static void main(String[] args) {

//请在此添加实现代码
/********** Begin **********/
//定义float对象
        float f = 66.6f;

        //手动装箱
        Float f1 = new Float(f);

        //自动装箱
        Float f2 =   f    ;

        System.out.println("装箱后的结果为：" + f1 + "和" + f2);


        //定义一个Double包装类值为88.88
        Double d =  88.88d     ;

        //手动拆箱
        double d1 =   new Double(d)   ;

        //自动拆箱
        double d2 =   d   ;

        System.out.println("拆箱结果为：" + d1 + "和" + d2);


/********** End **********/

    }

}
