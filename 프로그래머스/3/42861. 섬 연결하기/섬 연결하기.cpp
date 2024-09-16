#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int u, v;
    int weight;
    
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

int parent[101];
priority_queue<Edge> pq;

int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a != b) {
        parent[b] = a;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for(auto cost : costs) {
        pq.push({cost[0], cost[1], cost[2]});
    }
    
    int edgeCount = 0;
    while(edgeCount < n - 1) {
        Edge edge = pq.top();
        int a = edge.u;
        int b = edge.v;
        int w = edge.weight;
        pq.pop();
        
        if(find(a) != find(b)) {
            merge(a, b);
            answer += w;
            edgeCount++;
        }
    }
    
    return answer;
}