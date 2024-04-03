import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int[] dp = new int[1000001];
        
        dp[1] = 0;
        
        for(int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + 1;  // 3.
            
            if(i % 3 == 0) {        // 1.
                dp[i] = Math.min(dp[i], dp[i / 3] + 1);
            }
            
            if(i % 2 == 0) {        // 2.
                dp[i] = Math.min(dp[i] , dp[i / 2] + 1);
            }
        }
        
        System.out.println(dp[N]);
        
        br.close();
    }
}