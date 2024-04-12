#include<bits/stdc++.h>
using namespace std;

int n, m;
int dist[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isOut(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void bfs(vector<vector<int>> maps) {
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isOut(nx, ny) || dist[nx][ny] != -1 || maps[nx][ny] == 0) {
                continue;
            }
            
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    
    memset(dist, -1, sizeof(dist));
    
    bfs(maps);
    
    return dist[n-1][m-1];
}