import java.util.Scanner;

public class scanner 
{
    public static void main(String[] args) 
    {
        System.out.println("이름 도시 나이 체중 독신 여부를 빈칸으로 구분하여 입력하세요.");
        Scanner scanner = new Scanner(System.in);
        String name = scanner.next();      
        System.out.print("이름 :" + name + ",");
        String city = scanner.next();
        System.out.print("도시 : " + city + ",");
        int age = scanner.nextInt();
        System.out.print("나이 :" + age + ",");      
        double weight = scanner.nextDouble(); 
        System.out.print("체중 :" + weight + ",");
        boolean isSingle = scanner.nextBoolean(); 
        System.out.print("독신 여부 :" + isSingle);
    }
}