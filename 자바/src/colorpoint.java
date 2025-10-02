
class point
{
    private int x, y;
    public void set(int x, int y) 
    {
        this.x = x;
        this.y = y;
    }
    public void showpoint()
    {
        System.out.println("(" + x + "," + y + ")");
    }
}

class color extends point
{
    private String color;
    public void setcolor(String color)
    {
        this.color = color;
    }
    public void showcolorpoint()
    {
        System.out.print(color);
        showpoint();
    }
}
public class colorpoint {

public static void main(String[] args) 
{
   point p = new point();
   p.set(1,2);
   p.showpoint();

   color cp = new color();
   cp.set(3,4);
   cp.setcolor("blue");
   cp.showcolorpoint();


}
}