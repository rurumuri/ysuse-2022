package hw02_OOP.hw04.step2;

import java.util.Scanner;

public class NameSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        /********** Begin *********/
        String data = scanner.nextLine();
        String target = scanner.nextLine();
        scanner.close();

        int lastcur = 0;
        while(true){
            int cur = data.indexOf(target);
            if(cur != -1){
                System.out.println(lastcur+cur);
                data = data.substring(cur+target.length());
                lastcur += (cur+target.length());
            }else{
                break;
            }
        }


        /********** End *********/
    }
}
