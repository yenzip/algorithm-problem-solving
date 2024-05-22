#include <bits/stdc++.h>
using namespace std;

int N;
int A[500][500];

void print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> A[i][j];
        }
    }
    
    for(int i = N - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            A[i][j] += max(A[i + 1][j], A[i + 1][j + 1]);
        }
    }
    
    cout << A[0][0];
    
    return 0;
}