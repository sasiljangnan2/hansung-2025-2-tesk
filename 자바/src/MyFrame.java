import java.awt.*;
import javax.swing.*;
public class MyFrame extends JFrame {
public MyFrame() {
    setTitle("contentpane과 jframe"); // 프레임 타이틀 설정
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 프레임 종료 설정
    Container contentPane = getContentPane(); // 컨텐트팬 얻기
    contentPane.setBackground(Color.GREEN); // 배경색 설정
    contentPane.setLayout(new BorderLayout(30,20)); // 레이아웃 매니저 설정

    contentPane.add(new JButton("OK"),BorderLayout.CENTER); // 컨텐트팬에 버튼 추가
    contentPane.add(new JButton("Cancel"), BorderLayout.NORTH); // 컨텐트팬에 버튼 추가
    contentPane.add(new JButton("Ignore"), BorderLayout.SOUTH); // 컨텐트팬에 버튼 추가
    contentPane.add(new JButton("TextField"),BorderLayout.EAST); // 컨텐트팬에 
    contentPane.add(new JButton("Ignore"),BorderLayout.WEST); // 컨텐트팬에 버튼 추가

    setSize(400,200); // 프레임 크기 300x300
    setVisible(true); // 프레임 출력
}
public static void main(String[] args) {
    new MyFrame();
}
}