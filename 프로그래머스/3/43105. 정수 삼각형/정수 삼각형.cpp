// 순서: 아래 -> 위

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle);
    
    for(int i = triangle.size() - 2; i >= 0; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    
    return dp[0][0];
}