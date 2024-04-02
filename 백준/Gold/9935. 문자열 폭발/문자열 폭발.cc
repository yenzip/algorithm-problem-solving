#include <bits/stdc++.h>
using namespace std;

string S, E;
deque<char> dq;
string answer;

int main() {
    
    cin >> S >> E;

    for(char c : S) {
        dq.push_back(c);
        
        if(c == E.back() && dq.size() >= E.size()) {
            string subS = string(dq.end() - E.size(), dq.end());
            
            if(subS == E) {
                for(int i = 0; i < E.size(); i++) {
                    dq.pop_back();
                }
            }
        }
    }
    
    answer = string(dq.begin(), dq.end());
    
    cout << (answer.empty() ? "FRULA" : answer);

    return 0;
}