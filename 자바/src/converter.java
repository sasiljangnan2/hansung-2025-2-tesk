 import java.util.Scanner;
 class rconverter {
    private static double rate;
    public static double toDollar(double won)
    {
        return won/rate;
    }
    public static double toKWR(double dollar)
    {
        return dollar * rate;
    }
    public static void setrate(double r)
    {
        rate = r;
    }
}
public class converter {
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("환율 입력: ");
        double rate = scanner.nextDouble();
        rconverter.setrate(rate);
        System.out.print("100만원 : $" + rconverter.toDollar(1000000));
        System.out.print("\n$100 : " + rconverter.toKWR(100));
    }
}
