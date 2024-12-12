#include <iostream>
#include <climits>
using namespace std;

long long A, B;
int answer;

void dfs(long long num, int count) {
    if(num > B) {
        return;
    }
    else if(num == B) {
        answer = count;
        return;
    } 

    // 1. 2를 곱한다
    dfs(num * 2, count + 1);
    
    // 2. 1을 수의 가장 오른쪽에 추가한다
    dfs(num * 10 + 1, count + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B;
    
    answer = INT_MAX;
    dfs(A, 1);
    
    cout << (answer == INT_MAX ? -1 : answer);

    return 0;
}