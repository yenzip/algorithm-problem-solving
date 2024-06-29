import java.io.*;
import java.util.*;

class Solution {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int answer = 0;
        
        while(N > 0) {
            answer += N % 10;
            N /= 10;
        }
        
        System.out.println(answer);
        
        br.close();
    }
}