package hw01_basic.hw08.step3;

import java.util.Scanner;

public class HelloWorld {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        /********** Begin **********/
        //将a的值赋给b   b的值赋给a
        int c = a;
        a = b;
        b = c;

        /********** End **********/
        System.out.println(a);
        System.out.println(b);
    }

}
