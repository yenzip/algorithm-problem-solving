#include <bits/stdc++.h>
using namespace std;

int K, N;
int A[10000];
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> K >> N;
    
    for(int i = 0; i < K; i++) {
        cin >> A[i];
    }
    
    long long left = 1;
    long long right = *max_element(A, A + K);
    
    while(left <= right) {
        long long mid = (left + right) / 2;    // N개로 만들 수 있는 랜선의 길이
        int cnt = 0;    // 랜선의 개수
        
        for(int i = 0; i < K; i++) {
            cnt += A[i] / mid;
        }
        
        if(cnt >= N) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
    
}