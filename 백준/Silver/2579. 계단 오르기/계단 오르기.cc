#include <bits/stdc++.h>
using namespace std;

int N;
int A[301];
int dp[301];    // dp[i]: i번째 계단에서 얻을 수 있는 점수의 최댓값

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    dp[1] = A[1];
    dp[2] = A[1] + A[2];
    dp[3] = max(A[1], A[2]) + A[3];
    
    for(int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + A[i - 1]) + A[i];
    }
    
    cout << dp[N];
    
    return 0;
}