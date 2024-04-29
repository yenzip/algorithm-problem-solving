#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000000];
vector<int> LCS;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    LCS.push_back(A[0]);
    
    for(int i = 1; i < N; i++) {
        if(LCS.back() < A[i]) {
            LCS.push_back(A[i]);
        } else {
            auto it = lower_bound(LCS.begin(), LCS.end(), A[i]);
            *it = A[i];
        }
    }
    
    cout << LCS.size();
    
    return 0;
}