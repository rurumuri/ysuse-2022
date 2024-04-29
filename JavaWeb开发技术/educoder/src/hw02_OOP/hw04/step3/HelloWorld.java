package hw02_OOP.hw04.step3;

public class HelloWorld {

    public void judge(String fileName,String email){
        //请在此添加实现代码
/********** Begin **********/
    if(fileName.lastIndexOf(".java") == fileName.length()-5 && fileName.lastIndexOf(".java") != 0){
        System.out.println("Java文件名正确");
    } else {
        System.out.println("Java文件名无效");
    }

    int indexofpoint = email.lastIndexOf(".");
    int indexofat = email.lastIndexOf("@");
    if(indexofpoint != -1 && indexofat != -1 && indexofat < indexofpoint){
        System.out.println("邮箱名正确");
    } else {
        System.out.println("邮箱名无效");
    }

/********** End **********/
    }


}
