import java.io.*;
import java.util.*;

class Solution {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        char answer;
        
        if(A == 1) {  // 가위
            answer = (B == 2 ? 'B' : 'A'); 
        } else if(A == 2) { // 바위
            answer = (B == 3 ? 'B' : 'A');
        } else { // 보
            answer = (B == 1 ? 'B' : 'A');
        }
        
        System.out.println(answer);
        
        br.close();
    }
}