#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[10000];
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    cin >> M;
    
    int left = 1;
    int right = *max_element(A, A + N);
    
    while(left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;
        
        for(int i = 0; i < N; i++) {
            sum += min(A[i], mid);
        }
        
        if(sum <= M) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer;
    
    return 0;
}