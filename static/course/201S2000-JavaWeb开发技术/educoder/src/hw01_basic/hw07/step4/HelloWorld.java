package hw01_basic.hw07.step4;


public class HelloWorld {
    public static void main(String[] args) {
        /********** Begin **********/
        int[][] scores = {
            {92, 85},
            {91, 65},
            {90, 33}
        };
        for (int i = 0; i < scores.length; i++) {
            for (int j = 0; j < scores[i].length; j++) {
                System.out.println(scores[i][j]);
            }
        }
        for (int i = 0; i < scores.length; i++) {
            for (int j = 0; j < scores[i].length; j++) {
                if(j==1){
                    scores[i][j]=2;
                }else if(j==0){
                    scores[i][j]=1;
                }
            }
        }
        for (int i = 0; i < scores.length; i++) {
            for (int j = 0; j < scores[i].length; j++) {
                System.out.println(scores[i][j]);
            }
        }








        /********** End **********/
    }
}
