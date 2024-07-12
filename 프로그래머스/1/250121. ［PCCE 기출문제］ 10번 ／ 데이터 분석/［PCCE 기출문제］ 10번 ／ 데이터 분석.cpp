#include <bits/stdc++.h>
using namespace std;

int sort_idx;

struct compare {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[sort_idx] > b[sort_idx];
    }
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    map<string, int> m = {
        {"code", 0},
        {"date", 1},
        {"maximum", 2},
        {"remain", 3}
    };
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    int idx = m[ext];
    sort_idx = m[sort_by];
    
    for(auto d : data) {
        if(d[idx] < val_ext) {
            pq.push(d);
        }
    }
    
    vector<vector<int>> answer;
    
    while(!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }
    
    return answer;
}