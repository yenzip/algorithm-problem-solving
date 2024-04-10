#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> maxPQ;  // 최대힙
    priority_queue<int, vector<int>, greater<int>> minPQ;   // 최소힙
    int size = 0;
    
    for(string op : operations) {
        char cmd = op[0];
        int val = stoi(op.substr(2));
        
        if(cmd == 'I') {    // 삽입
            maxPQ.push(val);
            minPQ.push(val);
            size++;
        } else {            // 삭제
            if(size == 0) {
                continue;
            }
            
            if(val == 1) {  // 최댓값 삭제
                maxPQ.pop();
            } else {        // 최솟값 삭제
                minPQ.pop();
            }
            
            size--;
        }
        
        if(size == 0) {
            maxPQ = priority_queue<int>();
            minPQ = priority_queue<int, vector<int>, greater<int>>();
        }
    }

    return size == 0 ? vector<int>{0, 0} : vector<int>{maxPQ.top(), minPQ.top()};
}