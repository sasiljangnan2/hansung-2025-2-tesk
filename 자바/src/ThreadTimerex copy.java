import java.awt.*;
import javax.swing.*;

class TimeThread extends Thread {
    private JLabel timerLabel;

    public TimeThread(JLabel timerLabel) {
        this.timerLabel = timerLabel;
    }

    public void run() {
        int time = 0;
        while (true) {
            time++;
            timerLabel.setText(Integer.toString(time));
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                return;
            }
           
        }
    }
}
public class ThreadTimerex extends JFrame {
    public ThreadTimerex() {
        setTitle("Thread를 이용한 타이머");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        JLabel timerLabel = new JLabel("0");
        timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
        
        c.add(timerLabel);
        

        TimerRunnable th = new TimerRunnable(timerLabel);
       
        th.start();
      

        setSize(300, 170);
        setVisible(true);
    }
    public static void main(String[] args) {
        new ThreadTimerex();
    }
   
}
