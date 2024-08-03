import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        String s = br.readLine();
        String bomb = br.readLine();
        int len = bomb.length();
        
        for(char c : s.toCharArray()) {
           sb.append(c);
           
           if(sb.length() < len || c != bomb.charAt(len - 1)) {
               continue;
           }
           
           int start = sb.length() - len;
           if(sb.substring(start).equals(bomb)) {
               sb.delete(start, start + len);
           }
        }
        
        if(sb.length() == 0) {
            sb.append("FRULA");
        }
        
        System.out.println(sb);
        
        br.close();
    }
}