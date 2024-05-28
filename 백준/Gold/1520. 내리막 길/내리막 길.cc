#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[501][501];
int dp[502][502];   // dp[i][j]: (i, j)까지 경로의 수 (= memoization)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y) {
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    
    dp[x][y] = 0;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(A[nx][ny] > A[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }
    }
    
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> A[i][j];
            dp[i][j] = -1;
        }
    }
    
    dp[1][1] = 1;
    
    cout << dfs(N, M);
    
    return 0;
}