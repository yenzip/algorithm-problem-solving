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

            while (i < N) {
                int left = i;

                // 왼쪽 증가하는 부분 찾기
                while (left < N - 1 && h[left] < h[left + 1]) {
                    left++;
                }

                // 증가하지 않은 경우 바로 넘어감
                if (left == i) {
                    i++;
                    continue;
                }

                int target = left;

                int right = target;

                // 오른쪽 감소하는 부분 찾기
                while (right < N - 1 && h[right] > h[right + 1]) {
                    right++;
                }

                // 감소하지 않은 경우 바로 넘어감
                if (right == target) {
                    i++;
                    continue;
                }

                // (target - i) * (right - target)로 가능한 경우의 수를 추가
                answer += (target - i) * (right - target);

                // i 값을 right 다음으로 이동
                i = right;
            }
            
            System.out.println("#" + tc + " " + answer);
        }
        
        sc.close();
    }
}