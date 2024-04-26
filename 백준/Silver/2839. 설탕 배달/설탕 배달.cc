#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    dp.resize(N + 1, 5000);
    
    dp[3] = dp[5] = 1;
    
    for(int i = 6; i <= N; i++) {
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
    }
    
    cout << (dp[N] >= 5000 ? -1 : dp[N]);
    
    return 0;
}