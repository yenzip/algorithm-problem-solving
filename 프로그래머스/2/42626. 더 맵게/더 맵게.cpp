#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int s : scoville) {
        pq.push(s);
    }
    
    while(pq.top() < K && pq.size() > 1) {
        int s1 = pq.top();
        pq.pop();
        
        int s2 = pq.top();
        pq.pop();
        
        pq.push(s1 + s2 * 2);
        answer++;
    }
    
    return pq.top() < K ? -1 : answer;
}