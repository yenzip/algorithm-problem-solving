#include <bits/stdc++.h>
using namespace std;

int N;

string check369(int x) {
    string s = to_string(x);
    int clap = 0;
    
    for(auto c : s) {
        if(c == '3' || c == '6' || c == '9') {
            clap++;
        }
    }
    
    return clap ? string(clap, '-') : s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cout << check369(i) << " ";
    }
    
    return 0;
}