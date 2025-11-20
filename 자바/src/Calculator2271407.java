import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Calculator2271407 extends JFrame{
    // 값 출력할 라벨들 
    private JLabel lax = new JLabel("0");
    private JLabel lat = new JLabel("+");
    private JLabel lay = new JLabel("0");
    private JLabel la = new JLabel("= 0");
    public Calculator2271407 (){
        setTitle("계산기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        GridLayout grid = new GridLayout(5,4); //그리드로 버튼과 라벨 배치
        grid.setVgap(3);
       
        Container c = getContentPane();
        // 라벨 배치
        c.setLayout(grid);
        c.add (lax);
        c.add (lat);
        c.add (lay);
        c.add(la);
        String[] buttons = { // 버튼에 들어갈 문자들
            "7","8","9","*",
            "4","5","6","-",
            "1","2","3","+",
            "c","0","/","="
        };
        for (String t : buttons) // 버튼 배치
        { 
            JButton b = new JButton(t);
            b.addActionListener(new ButtonListener());
            c.add(b);
        }        
        setSize(300,200);
        setVisible(true);
    }
    class ButtonListener implements ActionListener {
        static int isOpper = 0; //0이면 첫번째 숫자입력, 1이면 두번째 숫자입력
        public int isOperator (String op) //연산자인지 아닌지 판단하는 함수
        {
            if (op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/")) {
                return 1;
            }
            return 0;
        }
    public void actionPerformed(ActionEvent e) {
        JButton b = (JButton)e.getSource();
        int x = Integer.parseInt(lax.getText()); // 첫번째 숫자와 두번째 숫자 가져오기
        int y = Integer.parseInt(lay.getText());
        String op = lat.getText(); // 연산자 가져오기
        int result = 0;
        if (b.getText().equals("=")) // = 버튼 눌렀을 때 연산 수행
        {
            switch (op) {
                case "+":
                    result = x + y;
                    break;
                case "-":
                    result = x - y;
                    break;
                case "*":
                    result = x * y;
                    break;
                case "/":
                    if (y != 0) result = x / y;
                    else 
                    {
                        la.setText("error");
                        return;
                    }
                      break;
                }
                la.setText("= " + result);
         }
         else if (isOperator(b.getText()) == 1) // 연산자 버튼 눌렀을 때
         {
            isOpper = 1; // 두번째 숫자 입력 설정
            lat.setText(b.getText());
         }
         else if (b.getText().equals("c")) // c 버튼 눌렀을 때
        {
            /*lax.setText("0");
            lay.setText("0");
            lat.setText("+");
            la.setText("= 0");
            isOpper = 0;*/ // 과제 편의성을 위해 초기화를 구현했지만 과제 조건에 맞지 않아서 주석 처리했습니다.
         }
        else // 숫자 버튼 눌렀을 때
        {
            if (isOpper == 0) // 첫번째 숫자 입력 
            {
                if (lax.getText().equals("0")) //처음 입력일 때
                    lax.setText(b.getText());
                else 
                    lax.setText(lax.getText() + b.getText());
            }
            else // 두번째 숫자 입력
            {
                if (lay.getText().equals("0")) //처음 입력일 때
                    lay.setText(b.getText());
                else 
                    lay.setText(lay.getText() + b.getText());
            }
        }
    }
    
}
    public static void main(String[] args) // 메인함수
    {
     new Calculator2271407();
    }
}   
