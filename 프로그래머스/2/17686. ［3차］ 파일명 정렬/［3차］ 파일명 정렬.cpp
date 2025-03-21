#include <bits/stdc++.h>

using namespace std;

struct file {
    int index;
    string head;
    string number;
    string tail;
};

struct comp {
    bool operator()(const file &a, const file &b) {
        int a_number = stoi(a.number);
        int b_number = stoi(b.number);
        
        if(a.head == b.head) {
            if(a_number == b_number) {
                return a.index > b.index;
            }
            return a_number > b_number;
        }
        return a.head > b.head;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    priority_queue<file, vector<file>, comp> pq;
    
    for(int i = 0; i < files.size(); i++) {
        string head = "";
        int n_index = 0;
        while(!isdigit(files[i][n_index])) {
            head += tolower(files[i][n_index]);
            n_index++;
        }
        
        string number = "";
        int t_index = n_index;
        while(isdigit(files[i][t_index])) {
            number += files[i][t_index];
            t_index++;
        }
        
        string tail = files[i].substr(t_index);
        
        pq.push({i, head, number, tail});
    }
    
    while(!pq.empty()) {
        answer.push_back(files[pq.top().index]);
        pq.pop();
    }
    
    return answer;
}