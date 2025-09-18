public class fors {
    public static void main(String[] args) 
    {
        int sum = 0;
        for(int i=1; i<=10; i++) 
        {
            System.out.println(i);
            sum += i;
            if (i < 10) System.err.println("+");
            else 
            {
                System.out.println("=");
                System.out.println(sum);
            }
        }
    }
            
}
            
