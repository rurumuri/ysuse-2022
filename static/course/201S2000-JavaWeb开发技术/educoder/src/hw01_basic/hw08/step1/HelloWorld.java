package hw01_basic.hw08.step1;


import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        //动态构建arr1
        int[] arr1 = new int[3];
        Scanner sc = new Scanner(System.in);
        for(int i = 0 ; i< arr1.length ; i++){
            arr1[i] = sc.nextInt();
        }
        /********** Begin **********/
        //创建数组arr2
        int[] arr2 = new int[3];





        //使用for循环将arr1的数据复制给arr2
        for(int i = 0 ; i< arr2.length ; i++){
            arr2[i] = arr1[i];
        }


        //输出arr2
        for(int i = 0 ; i< arr2.length ; i++){
            System.out.println(arr2[i]);
        }


        /********** End **********/
    }
}
