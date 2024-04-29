package hw02_OOP.hw07.step4;

import java.util.Scanner;

public class Task {
    /********* Begin *********/
    public static void main(String[] args) throws MyException {
        Scanner sc = new Scanner(System.in);
        String username = sc.next();


        if (username.length()<3){
            throw new MyException("用户名小于三位Exception");
        }
        System.out.println("用户名格式正确");
    }
}

class MyException extends Exception {
    public MyException(String message) {
        super(message);
    }
    public MyException() {

    }
}

/********* End *********/