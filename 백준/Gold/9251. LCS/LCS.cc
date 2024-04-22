#include <bits/stdc++.h>
using namespace std;

string A, B;
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B;
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            if(A[i] == B[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    
    cout << dp[A.size()][B.size()];
    
    return 0;
}