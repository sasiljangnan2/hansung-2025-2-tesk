class shape
{
    public shape next;
    public shape() {next = null;}

    public void draw()
    {
        System.out.println("shape");
    }
}

class line extends shape
{
    public void draw()
    {
        System.out.println("line");
    }
}


class circle extends shape
{
    public void draw()
    {
        System.out.println("circle");
    }
}

class rectt extends shape
{
    public void draw()
    {
        System.out.println("rect");
    }
}
public class overriding {

static void paint(shape p)
{
    p.draw();
}
public static void main(String[] args) {
    line line = new line();
    paint(line);
    paint(new shape());
    paint(new rectt());
    paint(new circle());
    paint(new line());
}
}
