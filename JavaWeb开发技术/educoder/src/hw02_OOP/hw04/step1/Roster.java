package hw02_OOP.hw04.step1;

import java.util.Scanner;

public class Roster {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        /********** Begin *********/
        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();
        System.out.println(s1.length());
        System.out.println(s2.length());
        if (s1.equals(s2)) {
            System.out.println("相同");
        } else {
            System.out.println("不相同");
        }


        /********** End *********/
    }
}
