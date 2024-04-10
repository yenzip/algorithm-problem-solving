#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq;  // 최대힙
    
    for(string op : operations) {
        char cmd = op[0];
        int val = stoi(op.substr(2));
        
        if(cmd == 'I') {    // 삽입
            pq.push(val);
        } else {            // 삭제
            if(pq.empty()) {
                continue;
            }
            
            if(val == 1) {  // 최댓값 삭제
                pq.pop();
            } else {        // 최솟값 삭제
                priority_queue<int> tmp;
                
                while(pq.size() > 1) {
                    tmp.push(pq.top());
                    pq.pop();
                }
                
                pq = tmp;
            }
        }
    }
    
    if(pq.empty()) {
        return vector<int>{0, 0};
    }
    
    int max_val = pq.top();
    
    while(pq.size() > 1) {
        pq.pop();
    }
    
    return vector<int>{max_val, pq.top()};
}