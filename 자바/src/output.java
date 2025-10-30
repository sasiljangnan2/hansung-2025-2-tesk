import java.io.FileOutputStream;

public class output {
    public static void main(String[] args) {
        int b[] = {7, 51, 3, 4, -1,24,260};
        try {
            FileOutputStream fout = new FileOutputStream("c:\\Temp\\test1.out");
            for (int i = 0; i < b.length; i++) {
                fout.write(b[i]);
            }
            fout.close();
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("Error: " + e);
        }
        System.err.println("파일 출력 완료");
    }

}
