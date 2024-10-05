#include <bits/stdc++.h>
using namespace std;

int answer;
bool visited[50];

int diff(string word1, string word2) {
    int cnt = 0;
    for(int i = 0; i < word1.size(); i++) {
        if(word1[i] != word2[i]) {
            cnt++;
        }
    }
    return cnt;
}

void dfs(string word, string target, vector<string> words, int len) {
    if(word == target) {
        answer = min(answer, len);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        if(!visited[i] && diff(word, words[i]) == 1) {
            visited[i] = true;
            dfs(words[i], target, words, len + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    answer = 50;
    dfs(begin, target, words, 0);
    return answer;
}