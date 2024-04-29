package hw02_OOP.hw09.step2;


public class Point {
    private double x;
    private double y;

    public Point() {
        this(0, 0);
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
        System.out.println("Point constructor:" + this.toString());
    }

    public String toString() {
        return "[" + this.x + "," + this.y + "]";
    }

}
