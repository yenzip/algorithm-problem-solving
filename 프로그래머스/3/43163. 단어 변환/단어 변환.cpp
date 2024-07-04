#include <bits/stdc++.h>
using namespace std;

bool visited[50];
int answer;

bool isConvertible(string w1, string w2) {
    int result = 0;
    
    for(int i = 0; i < w1.size(); i++) {
        if(w1[i] != w2[i]) {
            result++;
        }
    }
    
    return result == 1;
}

void dfs(string now, int depth, string target, vector<string> words) {
    if(answer <= depth) {
        return;
    }
    
    if(now == target) {
        answer = min(answer, depth);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        if(!visited[i] && isConvertible(now, words[i])) {
            visited[i] = true;
            dfs(words[i], depth + 1, target, words);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    answer = 50;
    
    if(find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    dfs(begin, 0, target, words);
    
    return answer;
}