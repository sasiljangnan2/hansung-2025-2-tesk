interface phoneinterface
{
    final int TiMEOUT = 10000;
    void sendcall();
    void receivecall();
    default void printlogo()
    {
        System.out.println("**phone**");
    } 
}
interface mobilephoneinterface extends phoneinterface
{
    void sendSMS();
    void receiveSMS();
}
interface  mp3interface
{
    public void play();
    public void stop();
}
class PDA{
    public int calculate(int x, int y)
    {
        return x + y;
    }
}
class smarephone extends PDA implements mobilephoneinterface, mp3interface
{
    @Override
    public void sendcall()
    {
        System.out.println("따르릉");
    }
    @Override
    public void receivecall()
    {
        System.out.println("전화 왔음");
    }
    @Override
    public void sendSMS()
    {
        System.out.println("문자 왓음");
    }
    @Override
    public void receiveSMS()
    {
        System.out.println("문자 감");
    }
    @Override
    public void play()
    {
        System.out.println("음악연주");
    }
    @Override
    public void stop()
    {
        System.out.println("그만연주");
    }
    public void schedule()
    {
        System.out.println("일정관리");
    }
}
public class inter {
    public static void main(String[] args) {
        smarephone phone = new smarephone();
        phone.printlogo();
        phone.sendcall();
        phone.play();
        System.out.println("3 + 5 = " + phone.calculate(3, 5));
        phone.schedule();
    }

}
