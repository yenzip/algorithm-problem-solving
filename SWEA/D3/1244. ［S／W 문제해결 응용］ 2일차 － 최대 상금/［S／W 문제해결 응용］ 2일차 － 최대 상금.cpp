#include <bits/stdc++.h>
using namespace std;

int T, N;
string S;
int answer;

void dfs(int idx, int exchange) {
    if(exchange == N) {
        answer = max(answer, stoi(S));
        return;
    }
    
    for(int i = idx; i < S.size() - 1; i++) {
        for(int j = i + 1; j < S.size(); j++) {
            swap(S[i], S[j]);
            dfs(i, exchange + 1);
            swap(S[i], S[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for(int tc = 1; tc <= T; tc++) {
        cin >> S >> N;
        answer = 0;
        
        if(S.size() < N) {
            N = S.size();
        } 
                
        dfs(0, 0);
        
        cout << "#" << tc << " " << answer << "\n";
    }
    
    return 0;
}