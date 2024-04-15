#include <bits/stdc++.h>
using namespace std;

int N, K, S, X, Y;
int A[201][201];
vector<tuple<int, int, int>> virus;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

bool isOut(int x, int y) {
    return (x < 1 || x > N || y < 1 || y > N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> A[i][j];
            
            if(A[i][j] == 0) {
                continue;
            }
            
            virus.push_back(make_tuple(A[i][j], i, j));
        }
    }
    
    cin >> S >> X >> Y;
    
    sort(virus.begin(), virus.end());
    
    for(int i = 0; i < virus.size(); i++) {
        int x = get<1>(virus[i]);
        int y = get<2>(virus[i]);
        q.push({x, y});
    }
    
    while(S--) {
        int size = q.size();
        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isOut(nx, ny) || A[nx][ny] != 0) {
                    continue;
                }
                
                q.push({nx, ny});
                A[nx][ny] = A[x][y];
            }
        }
    }
    
    cout << A[X][Y];
    
    return 0;
}