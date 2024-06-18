import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int n = triangle.length;
        int[][] dp = triangle;
        
        for(int i = n - 1; i > 0; i--) {
            for(int j = 0; j < triangle[i].length - 1; j++) {
                dp[i - 1][j] += Math.max(dp[i][j], dp[i][j + 1]);
            }
        }
           
        return dp[0][0];
    }
}