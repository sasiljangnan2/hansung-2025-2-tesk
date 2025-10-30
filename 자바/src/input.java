import java.io.FileInputStream;

public class input {

     public static void main(String[] args) {
       byte b [] = new byte[7];
        try {
            FileInputStream fin = new FileInputStream("c:\\Temp\\test.out");
            int n =0, c;
            while((c = fin.read()) != -1) {
                b[n] = (byte)c;
                n++;
            
            }
            System.out.println("입력된 데이터:");
            for (int i = 0; i < b.length; i++) {
                System.out.println(b[i]);
            }
            fin.close();
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("Error: " + e);
        }
        
    }
}
