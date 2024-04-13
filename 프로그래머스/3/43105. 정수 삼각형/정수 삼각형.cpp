// 순서: 위 -> 아래

#include <bits/stdc++.h>
using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 0; i < triangle.size() - 1; i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }
    
    for(int j = 0; j < triangle.size(); j++) {
        answer = max(answer, dp[triangle.size() - 1][j]);
    }
    
    return answer;
}