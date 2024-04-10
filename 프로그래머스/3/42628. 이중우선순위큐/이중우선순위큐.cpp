#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소힙
    deque<int> dq;
    
    for(string op : operations) {
        char cmd = op[0];
        int val = stoi(op.substr(2));
        
        if(cmd == 'I') {    // 삽입
            pq.push(val);
        } else {            // 삭제
            if(pq.empty()) {
                continue;
            }
            
            while(!pq.empty()) {
                dq.push_back(pq.top());
                pq.pop();
            }
            
            if(val == 1) {  // 최댓값 삭제
                dq.pop_back();
            } else {        // 최솟값 삭제
                dq.pop_front();
            }
            
            while(!dq.empty()) {
                pq.push(dq.front());
                dq.pop_front();
            }
        }
    }
    
    while(!pq.empty()) {
        dq.push_back(pq.top());
        pq.pop();
    }
    
    if(dq.empty()) {
        return vector<int>{0, 0};
    }

    answer.push_back(dq.back());
    answer.push_back(dq.front());
    
    return answer;
}