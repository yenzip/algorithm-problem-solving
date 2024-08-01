import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int T = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < T; i++) {
            String s = br.readLine();
            System.out.println(checkPalindrome(s.toCharArray()));
        }
        
        br.close();
    }
    
    private static int checkPalindrome(char[] s) {
        int len = s.length;
        int i = 0, j = len - 1;
        
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                int tmpI = i + 1, tmpJ = j;
                while(tmpI <= tmpJ && s[tmpI] == s[tmpJ]) {
                    tmpI++;
                    tmpJ--;
                }
                if(tmpI > tmpJ) {
                    return 1;
                }
                
                tmpI = i; tmpJ = j - 1;
                while(tmpI <= tmpJ && s[tmpI] == s[tmpJ]) {
                    tmpI++;
                    tmpJ--;
                }
                if(tmpI > tmpJ) {
                    return 1;
                }
                
                return 2;
            }
        }
        
        return 0;
    }
}