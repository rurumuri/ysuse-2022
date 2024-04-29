/********** Begin **********/
//在这里添加包名  step4
package hw02_OOP.hw01.step4;

//创建类 添加属性和方法
public class WuMingFen {
    String theMa;
    int quantity;
    boolean likeSoup;
    public WuMingFen(String ma, int quantity, boolean likeSoup) {
        this.theMa = ma;
        this.quantity = quantity;
        this.likeSoup = likeSoup;
    }
    public WuMingFen(String ma, int quantity) {
        this.theMa = ma;
        this.quantity = quantity;
    }
    public WuMingFen() {
        this.theMa = "酸辣";
        this.quantity = 2;
        this.likeSoup = true;
    }
    public void check(){
        System.out.println("面码："+this.theMa+"，粉的份量："+this.quantity+"两，是否带汤："+this.likeSoup);

    }
}

/********** End **********/
