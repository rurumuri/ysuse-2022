package hw01_basic.hw08.step2;


import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //str为要查找的字符串
        String str = sc.next();

        /********** Begin **********/
        //创建数组   arr  给数组赋值 {"张三","张三丰","张无忌","王二麻子","张富贵"}
        String[] arr = {"张三","张三丰","张无忌","王二麻子","张富贵"};
        for (int i = 0; i < arr.length; i++) {
            if(str.equals(arr[i])) {
                System.out.println(str+"在数组的第"+(i+1)+"个位置");
            }
        }
        /********** End **********/
    }
}
