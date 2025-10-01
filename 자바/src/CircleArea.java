public class CircleArea {
// main() 메소드에서 실행 시작
    int radius; // 반지름
    String name;
    public CircleArea() {
        radius = 1; 
        name = " ";
    }
    public CircleArea(int radius)
    {
        this (radius, "원");
        this.radius = radius;
        
    }
    public CircleArea(int r, String n)
    {
        radius = r; 
        name = n;
    }

    public double getArea() {
        final double PI = 3.14; // 원주율 상수
        return radius * radius * PI; // 원의 넓이
    }


public static void main(String[] args) 
{
    CircleArea [] c = new CircleArea[5];
    for (int i = 0; i < 5; i++)
    {
        c[i] = new CircleArea(i);
        System.out.println(c[i].name + "의 면적은 " + c[i].getArea());
    } 
    
}
}
