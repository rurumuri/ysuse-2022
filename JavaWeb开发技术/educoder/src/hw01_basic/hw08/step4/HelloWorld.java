package hw01_basic.hw08.step4;

import java.util.Arrays;
import java.util.Scanner;

public class HelloWorld {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //动态创建数组
        int[] arr = new int[sc.nextInt()];
        for(int i = 0 ; i< arr.length ; i++){
            arr[i] = sc.nextInt();
        }
        /********** Begin **********/
        for(int i = 0 ; i< arr.length ; i++){
            for(int j = i ; j< arr.length ; j++){
                if(arr[j]>arr[i]){
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }

        System.out.println(Arrays.toString(arr));

        /********** End **********/
    }
}
