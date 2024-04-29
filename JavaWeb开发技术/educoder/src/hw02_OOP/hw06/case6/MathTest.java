package hw02_OOP.hw06.case6;

import java.util.Scanner;
import java.lang.Math;

public class MathTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a1 = sc.nextInt();
        int a2 = sc.nextInt();
        int a3 = sc.nextInt();
        int a4 = sc.nextInt();
        double a5 = sc.nextDouble();
        double a6 = sc.nextDouble();
        double a7 = sc.nextDouble();
        double a8 = sc.nextDouble();
        double a9 = sc.nextDouble();
        double a10 = sc.nextDouble();
        double a11 = sc.nextDouble();
        /********* Begin *********/
        System.out.println(Math.sqrt(a1));
        System.out.println(Math.cbrt(a2));
        System.out.println(Math.pow(a3, a4));
        System.out.println(Math.max(a5, a6));
        System.out.println(Math.min(a5, a6));
        System.out.println(Math.abs(a7));
        System.out.println(Math.ceil(a8));
        System.out.println(Math.floor(a9));
        System.out.println(Math.rint(a10));
        System.out.println(Math.round(a11));
        /********* End *********/
    }
}