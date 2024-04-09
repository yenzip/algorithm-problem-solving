#include <bits/stdc++.h>
using namespace std;

int N;
int A[20][20];
bool visited[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer, shark_size = 2;
typedef tuple<int, int, int> t;

bool isOut(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= N);
}

void simulation(int sx, int sy) {
    // 우선순위 큐 정렬 조건: 1. 거리순, 2. x 좌표, 3. y 좌표
    priority_queue<t, vector<t>, greater<t>> pq;
    int eat = 0;    // [eat] : size 크기의 아기상어가 먹은 물고기 수
    
    pq.push(t(0, sx, sy));
    visited[sx][sy] = true;
    
    while(!pq.empty()) {
        int dist = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();
        
        if(A[x][y] != 0 && A[x][y] < shark_size) {
            answer = dist;
            eat++;
            
            if(eat == shark_size) {
                shark_size++;
                eat = 0;
            }
            
            pq = priority_queue<t, vector<t>, greater<t>>();
            memset(visited, false, sizeof(visited));
            
            pq.push(make_tuple(0, x, y));
            visited[x][y] = true;
            A[x][y] = 0;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isOut(nx, ny) || visited[nx][ny] || A[nx][ny] > shark_size) {
                continue;
            }
            
            pq.push(make_tuple(dist + 1, nx, ny));
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int sx, sy; // [sx, sy] : 상어의 좌표
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
            
            if(A[i][j] == 9) {
                sx = i;
                sy = j;
                A[i][j] = 0;
            }
        }
    }
    
    simulation(sx, sy);
    
    cout << answer;
    
    return 0;
}