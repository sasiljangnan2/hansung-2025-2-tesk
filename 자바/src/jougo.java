import java.util.Scanner;
public class jougo 
{
    public static void main(String[] args) 
    {
        int i , N;
        Character ctemp;
        int num[] = new int[1000000];
        String arr = "", temp = "";
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        for (i = N -1; i >= 0; i--) 
        {
            num[i] = scanner.nextInt();
        }
        for (i = 0; i < N; i++)
        {
           temp = Integer.toString(i + 1);
            switch (num[i])
            {
            case 1:
            {
                arr = temp + arr;
                break;
            }
            case 2:
            {
                ctemp = arr.charAt(0);
                if (arr.length() < 2)
                {
                    arr = arr + temp;
                    break;
                }
                else arr = ctemp + temp + arr.substring(1);
                break;
            }
            case 3:
            {
                arr = arr + temp;
                break;
            }
            default:
                break;
            }
        }
        for (i = 0; i <N; i++) 
        {
            System.out.print(arr.charAt(i) + " ");
        }
    }
}
