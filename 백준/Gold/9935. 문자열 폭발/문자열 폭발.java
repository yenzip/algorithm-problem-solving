import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        String e = br.readLine();

        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            sb.append(c);
            
            if(c == e.charAt(e.length() - 1) && sb.length() >= e.length()) {
                int offset = sb.length() - e.length();
                boolean isExplosion = true;
                
                for(int i = 0; i < e.length(); i++) {
                    if(sb.charAt(offset + i) != e.charAt(i)) {
                        isExplosion = false;
                        break;
                    }
                }
                
                if(isExplosion) {
                    sb.delete(offset, offset + e.length());
                }
            }
        }

        System.out.println(sb.length() == 0 ? "FRULA" : sb.toString());

        br.close();
    }
}