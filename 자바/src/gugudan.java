import java.util.InputMismatchException;
import java.util.Scanner;
public class gugudan {
    public static void main(String[] args) 
    {
        int dan;
        Scanner scanner = new Scanner(System.in);
        while(true)
        {
            System.out.print("출력할 단을 입력하세요:");
            try 
            {
                dan = scanner.nextInt();
            } 
            catch(InputMismatchException e) 
            {
                String ex = scanner.nextLine(); // 현재 입력 스트림에 남아 있는토큰은 읽어서 지워 버린다.
                System.out.println(ex+" 는 정수가 아님 종료합니다.");
                return;
            }
            
            for(int i=1; i<=9; i++)  System.out.println(dan + " * " + i + " = " + dan*i);
        }
        
    }
            
}