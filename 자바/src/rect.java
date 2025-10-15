import java.util.Scanner;

public class rect {
// main() 메소드에서 실행 시작
    int w;
    int h;
    

    public double getArea() {
      
        return w * h;
    }


public static void main(String[] args) 
{
    rect rect; 
    rect = new rect();
    Scanner sc = new Scanner(System.in);
    rect.w = sc.nextInt(); 
    rect.h = sc.nextInt(); 
    double area = rect.getArea();
    System.out.println("사각형의 넓이 : " + area);
}
}