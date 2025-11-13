import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseListenerRx extends JFrame {
    private JLabel la = new JLabel("Hello");
    public MouseListenerRx() {
        setTitle("Mouse Listener Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.addMouseListener(new MyMouseListener());

        c.setLayout(null);
        la.setSize(50,20);
        la.setLocation(30,30);
        c.add(la);

        setSize(300, 200);
        setVisible(true);
    }
    class MyMouseListener extends MouseAdapter {
        public void mousePressed(MouseEvent e) {
            int x = e.getX();
            int y = e.getY();
            la.setLocation(x, y);
        }
    }
    public static void main(String[] args) {
        new MouseListenerRx();
    }
}
