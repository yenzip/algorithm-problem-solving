#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100000];
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int left = *max_element(A, A + N);
    int right = accumulate(A, A + N, 0);
    
    while(left <= right) {
        int mid = (left + right) / 2;   // 블루레이의 크기
        int sum = 0, bluray = 1;
        
        for(int i = 0; i < N; i++) {
            if(sum + A[i] > mid) {
                sum = 0;
                bluray++;
            }
            sum += A[i];
        }
        
        if(bluray <= M) {
            answer = mid;  
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer;
    
    return 0;
}