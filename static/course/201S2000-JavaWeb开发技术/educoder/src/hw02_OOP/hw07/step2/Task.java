package hw02_OOP.hw07.step2;


import java.util.Scanner;

public class Task {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        /********* Begin *********/


        try{
            System.out.println(num1/num2);
        }catch(ArithmeticException e){
            System.out.println("除数不能为0");
        }


        /********* End *********/
    }

}
