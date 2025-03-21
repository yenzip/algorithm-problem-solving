#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> reverse_graph;
bool visited[101];

int dfs(vector<vector<int>> &g, int now) {
    visited[now] = true;
    int cnt = 1;
    
    for(int next : g[now]) {
        if(!visited[next]) {
            cnt += dfs(g, next);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    graph.resize(n + 1);
    reverse_graph.resize(n + 1);
    
    for(auto result : results) {
        int a = result[0];
        int b = result[1];
        
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        int win = dfs(graph, i);
        
        memset(visited, false, sizeof(visited));
        int lose = dfs(reverse_graph, i);
        
        if(win + lose - 1 == n) {
            answer++;
        }
    }
    
    return answer;
}