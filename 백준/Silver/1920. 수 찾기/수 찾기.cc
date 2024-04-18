#include <bits/stdc++.h>
using namespace std;

int N, M, x;
int A[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A + N);
    
    cin >> M;
    
    for(int j = 0; j < M; j++) {
        cin >> x;
        cout << binary_search(A, A + N, x) << "\n";
    }
    
    return 0;
}