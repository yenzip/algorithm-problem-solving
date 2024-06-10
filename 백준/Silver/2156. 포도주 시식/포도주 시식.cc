#include <bits/stdc++.h>
using namespace std;

int N;
int A[10001];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    dp[1] = A[1];
    dp[2] = A[1] + A[2];
    
    for(int i = 3; i <= N; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + A[i - 1]) + A[i]);
    }
    
    cout << dp[N];
    
    return 0;
}