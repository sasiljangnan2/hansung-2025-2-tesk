public class array {
    static void replace(char a[])
    {
        for(int i =0; i<a.length; i++)
        {
            if(a[i] == ' ')
            {
              a[i] = ',';
            }
        }
    }
    static void printchar (char a[])

    {
        for(int i =0; i<a.length; i++)
        {
            System.out.print(a[i]);
        }
        System.out.println();
    }

    public static void main(String args[]) 
    {
        char c[] = {'T', 'H', 'I', 'S', ' ', 'I', 'S'};
        printchar(c);
        replace(c);
        printchar(c);
    }
    
}
