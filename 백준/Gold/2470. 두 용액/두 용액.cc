#include <bits/stdc++.h>
using namespace std;

int N;
int A[100000];
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A, A + N);
    
    int left = 0;
    int right = N - 1;
    int abs_val = 2000000000;
    
    while(left < right) {
        int sum = A[left] + A[right];
        
        if(abs(sum) < abs_val) {
            abs_val = abs(sum);
            answer = { A[left], A[right] };
        }
        
        if(sum <= 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << answer[0] << " " << answer[1];
    
    return 0;
}