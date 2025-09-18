import java.util.Scanner;

public class zere {
    public static void main(String[] args) 
    {
    Scanner scanner = new Scanner(System.in);

    int dividend;
    int divisor;

    System.out.print("나늼수 입력:");
    dividend = scanner.nextInt();
    System.out.print("나눗수 입력:");
    divisor = scanner.nextInt();
    try {
        System.out.printf("%d / %d = %d\n", dividend, divisor, dividend / divisor);
    } catch (ArithmeticException e) {
        System.out.println("0으로 나눌 수 없습니다.");
    } 
}
}