#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long min_time = 1;
    long long max_time = (long long) times.back() * n;
    
    while(min_time <= max_time) {
        long long mid_time = (min_time + max_time) / 2;
        
        long long people = 0; // 지나간 사람 수
        
        for(int time : times) {
            people += mid_time / time;
        }
        
        if(people >= n) {
            max_time = mid_time - 1;
            answer = mid_time;
        } else {
            min_time = mid_time + 1;
        } 
    }
    
    return answer;
}