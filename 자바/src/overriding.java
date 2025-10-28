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
    @Override
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
    circle circle = new circle();
    rectt rectt = new rectt();
    line.draw();
    circle.draw();
    rectt.draw();
}
}
