import java.io.*;
import java.util.*;
 
class Solution {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
         
        int T = Integer.parseInt(st.nextToken());
         
        for(int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
             
            int N = Integer.parseInt(st.nextToken());
            int[] A = new int[N];
               
            int M = Integer.parseInt(st.nextToken());
            int[] B = new int[M];
               
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++) {
              A[i] = Integer.parseInt(st.nextToken());
            }
               
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < M; i++) {
                B[i] = Integer.parseInt(st.nextToken());
            }
               
            int maxLength = Math.max(N, M);
            int minLength = Math.min(N, M);
            int[] L, S;
               
            if(maxLength == N) {
                L = A;
                S = B;
            } else {
                L = B;
                S = A;
            }
             
            int answer = 0;
             
            for(int i = 0; i <= maxLength - minLength; i++) {
                int sum = 0;
                for(int j = 0, k = i; j < minLength; j++, k++) {
                    sum += L[k] * S[j];
                }
                answer = Math.max(answer, sum);
            }
             
            System.out.println("#" + tc + " " + answer);
        }
         
        br.close();
    }
}