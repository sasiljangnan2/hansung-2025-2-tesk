import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class TimerRunnable implements Runnable {
    private JLabel timerLabel;

    public TimerRunnable(JLabel timerLabel) {
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
public class ThreadInterruptex extends JFrame {
    private Thread th;
    public ThreadInterruptex() {
        setTitle("Thread를 이용한 타이머");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        JLabel timerLabel = new JLabel("0");
        timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
        
        c.add(timerLabel);
        

        TimerRunnable runnable = new TimerRunnable(timerLabel);
        th = new Thread(runnable);
        JButton btnKill = new JButton("Stop");
        JButton btnStart = new JButton("Start");
        btnStart.setEnabled(false);
        btnKill.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e)
             {
                th.interrupt();
                
                btnKill.setEnabled(false);
                btnStart.setEnabled(true);
                
             }
        }  );
        
        btnStart.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e)
             {
                TimerRunnable runnable = new TimerRunnable(timerLabel);
                th = new Thread(runnable);
                th.start();
                btnStart.setEnabled(false);
                btnKill.setEnabled(true);
    
             }
        }  );

        c.add(btnKill);
        c.add(btnStart);
        setSize(300, 170);
        setVisible(true);
        th.start();
    }
    public static void main(String[] args) {
        new ThreadInterruptex();
    }
   
}
