#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
map<int, int> mp;    // {oil_num, mass}

bool isInvalid(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs(vector<vector<int>> &land, int oil_num, int x, int y) {
    queue<pair<int, int>> q;
    int res = 0;

    visited[x][y] = true;
    q.push({x, y});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        land[x][y] = oil_num;
        res++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isInvalid(nx, ny) || land[nx][ny] == 0 || visited[nx][ny]) {
                continue;
            }
            
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return res;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    
    int oil_num = 1;
    
    // 1. 석유 덩어리 확인
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(land[i][j] == 1 && !visited[i][j]) {
                int mass = bfs(land, oil_num, i, j);  // 석유량
                mp[oil_num] = mass;
                oil_num++;                
            }
        }
    }
    
    // 2. 열 별 최대 석유량 측정
    for(int j = 0; j < m; j++) {
        vector<bool> check(oil_num);    // 석유 덩어리 번호 중복 체크
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            int num = land[i][j];
            
            if(num && !check[num]) {
                sum += mp[num];
                check[num] = true;
            }
        }
        
        answer = max(answer, sum);
    }
    
    return answer;
}