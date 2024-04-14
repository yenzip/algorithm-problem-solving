#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int div_num = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(auto p : puddles) {
        dp[p[1]][p[0]] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i][j] == -1) {
                continue;
            }
            
            int a = 0, b = 0;
            
            if(dp[i - 1][j] != -1) {
                a = dp[i - 1][j];
            }
            if(dp[i][j - 1] != -1) {
                b = dp[i][j - 1];
            }
            
            dp[i][j] += (a + b) % div_num;
        }
    }
    
    return dp[n][m];
}