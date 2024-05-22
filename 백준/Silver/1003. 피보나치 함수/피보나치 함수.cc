#include <bits/stdc++.h>
using namespace std;

int T, N;
int f[41];
int dp[41][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    f[0] = 0, f[1] = 1;
    dp[0][0] = 1, dp[1][1] = 1;
    
    for(int i = 2; i <= 40; i++) {
        f[i] = f[i - 1] + f[i - 2];
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    
    cin >> T;

    while(T--) {
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << "\n";
    }
    
    return 0;
}