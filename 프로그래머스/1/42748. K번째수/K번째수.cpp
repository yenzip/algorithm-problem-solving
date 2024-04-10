#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto command : commands) {
        int s = command[0] - 1;
        int e = command[1];
        int k = command[2] - 1;
        
        vector<int> tmp(array.begin() + s, array.begin() + e);  // 부분 배열 복사
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[k]);
    }
    
    return answer;
}