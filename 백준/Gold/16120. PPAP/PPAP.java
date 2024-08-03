import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        String s = br.readLine();
        String answer = "NP";
        
        for(char c : s.toCharArray()) {
            sb.append(c);
            
            if(sb.length() < 4 || c == 'A') {
                continue;
            }
            
            int start = sb.length() - 4;
            if(sb.substring(start).equals("PPAP")) {
                sb.delete(start, start + 3);
            }
        }
        
        if(sb.toString().equals("P")) {
            answer = "PPAP";
        }
        
        System.out.println(answer);
        
        br.close();
    }
}