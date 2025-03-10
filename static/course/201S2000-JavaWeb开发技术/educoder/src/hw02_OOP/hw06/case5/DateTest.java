package hw02_OOP.hw06.case5;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class DateTest {
    public static void main(String[] args) throws ParseException {
        // 键盘录入你的出生年月日 格式为yyyy-MM-dd
        // 把该字符串转换为一个日期
        // 通过该日期得到一个毫秒值
        // 获取2020年10月1日的毫秒值
        // 两者想减得到一个毫秒值
        // 把该毫秒值转换为天 打印输出
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        /********* Begin *********/
        Date date = new SimpleDateFormat("yyyy-MM-dd").parse(line);
        Long birTimeMillis = date.getTime();
        Long stdTimeMillis = new SimpleDateFormat("yyyy-MM-dd").parse("2020-10-01").getTime();
        System.out.println("你的出生日期距离2020年10月1日:"+(stdTimeMillis - birTimeMillis)/(1000*60*60*24)+"天");
        /********* End *********/
    }
}