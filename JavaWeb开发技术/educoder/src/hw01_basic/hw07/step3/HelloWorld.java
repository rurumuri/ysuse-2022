package hw01_basic.hw07.step3;

import java.util.Scanner;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] scores = new int[sc.nextInt()];

        //循环给数组赋值
        for(int i = 0 ; i< scores.length;i++){
            scores[i] = sc.nextInt();
        }
        /********** Begin **********/
        //在这里计算数组scores的平均值和最大值
        int smax = scores[0];
        int ssum = 0;
        for(int i = 0 ; i< scores.length;i++){
            if(smax<scores[i]){
                smax = scores[i];
            }
            ssum += scores[i];
        }

        System.out.printf("平均值：%.1f\n", (double)ssum / scores.length );
        System.out.println("最大值：" + smax );
        /********** End **********/
    }
}
