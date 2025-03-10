package hw02_OOP.hw06.case2;

import java.util.Scanner;

public class WrapperTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int aa = sc.nextInt();
        String bb = sc.next();
        int c = sc.nextInt();
        String str11 = sc.next();
        String str22 = sc.next();
        // 包装类中“==”与equals的用法比较
        // 值得注意的是，包装类中的equals方法和String类一样，都是重写了Object类中的equals方法，因此比较的是内容而不是地址，
        // 而“==”比较的依然是引用变量的地址，只是当包装类型和与之相对应的基本类型进行“==”比较时会先做自动拆箱处理。
        /********* Begin *********/
        Integer a = new Integer(aa);
        Integer b = new Integer(bb);

        System.out.println(a == b);
        System.out.println(a == c);
        System.out.println(b == c);
        System.out.println(a.equals(b));
        System.out.println(str11 == str22);
        System.out.println(str11.equals(str22));
        /********* End *********/
    }
}