import java.util.Scanner;
class Caffe
    {
        int Stuff, Part_Time_job, American_Coffee, Latte,Cappuccino;
        int American_Coffee_Quantity, Latte_Quantity, Cappuccino_Quantity;
        int Total_American_Coffee, Total_Latte, Total_Cappuccino;
        int Total_Sales, Total_Expense;
        int Profit;
        Scanner scanner = new Scanner(System.in);
        Caffe(int Stuff, int Part_Time_job, int American_Coffee, int Latte, int Cappuccino)
        {
            this.Stuff = Stuff;
            this.Part_Time_job = Part_Time_job;
            this.American_Coffee = American_Coffee;
            this.Latte = Latte;
            this.Cappuccino = Cappuccino;
        }
        void Sales_Quantity()
        {
            System.out.println("1일 판매 수량");
            System.out.println("    -아메리카노: " );
            this.American_Coffee_Quantity = scanner.nextInt();
            System.out.println("    -카페라떼: ");
            this.Latte_Quantity = scanner.nextInt();
            System.out.println("    -카푸치노: ");
            this.Cappuccino_Quantity = scanner.nextInt();
           
        }
        void Sales()
        {
            Total_American_Coffee = American_Coffee * American_Coffee_Quantity;
            Total_Latte = Latte * Latte_Quantity;
            Total_Cappuccino = Cappuccino * Cappuccino_Quantity;
            Total_Sales = Total_American_Coffee + Total_Latte + Total_Cappuccino;
            Part_Time_job *= 8;
            Profit = Total_Sales - (Stuff + Part_Time_job);
        }
        void print_Total_Sales()
        {
            String Stuff_c = String.format("%,d", Stuff);
            String Part_Time_job_c = String.format("%,d", Part_Time_job);
            String Total_American_Coffee_c = String.format("%,d", Total_American_Coffee);
            String Total_Latte_c = String.format("%,d", Total_Latte);   
            String Total_Cappuccino_c = String.format("%,d", Total_Cappuccino);
            String Profit_c = String.format("%,d", Profit);
            System.out.println("1일 재료비 : " + Stuff_c + "원");
            System.out.println("1일 아르바이트비 : " + Part_Time_job_c + "원");
            System.out.println("판매 금액"); 
            System.out.println(" -아메리카노: " + Total_American_Coffee_c + "원");
            System.out.println(" -카페라떼: " + Total_Latte_c + "원");
            System.out.println(" -카푸치노: " + Total_Cappuccino_c + "원");
            System.out.println("1일 순이익 : " + Profit_c + "원");
        }
    }
public class Total2271407 {
    public static void main(String[] args) {
        Caffe caffe = new Caffe(20000, 5000, 2000, 3000, 3500);
        caffe.Sales_Quantity();
        caffe.Sales();
        caffe.print_Total_Sales();
    }
    
}
