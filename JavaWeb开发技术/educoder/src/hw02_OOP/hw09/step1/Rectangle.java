package hw02_OOP.hw09.step1;

public class Rectangle {
    private double width;
    private double length;

    public Rectangle(){
        this.width=5;
        this.length=6;
    }

    public Rectangle(double w,double l){
        this.width=w;
        this.length=l;
    }

    public double area(){
        return this.width*this.length;
    }

    public double perimeter(){
        return 2*(this.width+this.length);
    }

    public static void main(String[] args) {
        Rectangle r1=new Rectangle();
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

}
