public class foreach {
    enum week {월,화,수,목,금,토,일};
    public static void main(String[] args)
    {
        int [] n = {1,2,3,4,5};
        String names[] = {"사과", "배", "귤", "바나나"};
        int sum = 0;
        for(int k : n)
        {
            System.out.print(k + " ");
            sum += k;
        }
        System.out.println("합 =" + sum);
        for (String s : names)
        {
            System.out.print(s + " ");
        }
        for(week day : week.values())
        {
            System.out.print(day + "요일 ");
        }
    }
    
}
