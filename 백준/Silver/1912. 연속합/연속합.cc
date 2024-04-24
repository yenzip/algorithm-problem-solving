#include <bits/stdc++.h>
using namespace std;

int n;
int A[100000];
vector<int> dp;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        dp.push_back(A[i]);
    }
    
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1] + A[i]);
    }
    
    answer = *max_element(dp.begin(), dp.end());
    
    cout << answer;
    
    return 0;
}