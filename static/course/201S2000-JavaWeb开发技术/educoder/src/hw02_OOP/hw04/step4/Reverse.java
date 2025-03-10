package hw02_OOP.hw04.step4;

public class Reverse {
    public static StringBuffer start(String data) {
        StringBuffer ans = new StringBuffer();
        /********** Begin *********/
        String[] words = data.split(" ");
        for (int i = 0; i < words.length; i++) {
            if(i!=0) ans.append(' ');
            StringBuffer temp = new StringBuffer(words[i]);
            ans.append(temp.reverse().toString());
        }


        /********** End *********/
        return ans;
    }
}
