#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> reverseGraph;
bool visited[101];

int dfs(vector<vector<int>> graph, int now) {
    int ret = 1;
    for(int next : graph[now]) {
        if(!visited[next]) {
            visited[next] = true;
            ret += dfs(graph, next);
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    graph.resize(n + 1);
    reverseGraph.resize(n + 1);
    
    for(vector<int> result : results) {
        int a = result[0];
        int b = result[1];
        
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        int count1 = dfs(graph, i);
        
        memset(visited, false, sizeof(visited));
        int count2 = dfs(reverseGraph, i);
        
        if(count1 + count2 == n + 1) {
            answer++;
        }
    }
    
    return answer;
}