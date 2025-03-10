package hw02_OOP.hw05.step3;

public class Task {
    public static void main(String[] args) {
        double a = 78.5;

//请在此添加实现代码
/********** Begin **********/
//将基本类型a转换为字符串
        String str = Double.toString(a);

        System.out.println("str + 12  的结果为： "+(str + 12));

        String str1 = "180.20";
        // 将字符串str1转换为基本类型
        double d = Double.parseDouble(str1);

        System.out.println("d + 100 的结果为： "+ (d + 100));

/********** End **********/


    }
}
