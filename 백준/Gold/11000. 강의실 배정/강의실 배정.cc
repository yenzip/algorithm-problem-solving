#include <bits/stdc++.h>
using namespace std;

int N, S, T;
vector<pair<int, int>> times; 
priority_queue<int, vector<int>, greater<int>> pq; // 종료 시간을 오름차순으로 저장한 우선선위 큐

int main() {
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> S >> T;
        times.push_back({S, T});
    }
    
    sort(times.begin(), times.end());
    
    for(int i = 0; i < N; i++) {
        if(!pq.empty() && pq.top() <= times[i].first) {
            pq.pop();
        }
        pq.push(times[i].second);
    }
    
    cout << pq.size();
    
    return 0;
}