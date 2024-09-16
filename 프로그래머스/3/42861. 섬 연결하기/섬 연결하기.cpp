#include <string>
#include <algorithm>
using namespace std;

int parent[101];

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

// 유니온 파인드
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
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int w = costs[i][2];
        
        if(find(a) != find(b)) {    // 사이클 확인
            merge(a, b);
            answer += w;
        }
    }
    
    return answer;
}