import java.util.*;

public class Solution {
    static long[] h;
    static int answer;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        
        for(int tc = 1; tc <= T; tc++) {
            int N = sc.nextInt();
            
            h = new long[N];
            answer = 0;

            for(int i = 0; i < N; i++) {
                h[i] = sc.nextLong();
            }
            
            int i = 0;

            while (i < N - 1) {
                int left = 0;
                int right = 0;

                // 왼쪽 증가하는 부분 찾기
                while (i < N - 1 && h[i] < h[i + 1]) {
                	left++;
                    i++;
                }

                // 오른쪽 증가하는 부분 찾기
                while (i < N - 1 && h[i] > h[i + 1]) {
                    right++;
                    i++;
                }

                answer += left * right;
            }
            
            System.out.println("#" + tc + " " + answer);
        }
        
        sc.close();
    }
}