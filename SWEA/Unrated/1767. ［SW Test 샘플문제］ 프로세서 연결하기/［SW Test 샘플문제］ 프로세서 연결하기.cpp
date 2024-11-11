#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

// 프로세서 구조체 정의
struct Processor {
    int x, y;
};

// 전역 변수 선언
int T, N;
int grid[12][12];
bool visitedGrid[12][12];
vector<Processor> processors;

// 방향 배열: 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 최대 연결된 프로세서 수와 최소 전선 길이
int maxConnected = 0;
int minWireLength = INT_MAX;

// 프로세서가 가장자리에 있는지 확인
bool isEdge(int x, int y) {
    return (x == 0 || x == N - 1 || y == 0 || y == N - 1);
}

// 특정 방향으로 전선을 연결할 수 있는지 확인
bool canConnect(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    // 경계에 도달할 때까지 검사
    while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
        if (grid[nx][ny] == 1 || visitedGrid[nx][ny]) {
            return false; // 다른 프로세서나 전선과 겹침
        }
        nx += dx[dir];
        ny += dy[dir];
    }
    
    return true; // 연결 가능
}

// 특정 방향으로 전선을 연결하거나 해제
int setConnection(int x, int y, int dir, bool connect) {
    int wireLength = 0;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    // 전선을 연결하거나 해제할 경로를 따라가며 visitedGrid를 업데이트
    while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
        visitedGrid[nx][ny] = connect;
        wireLength++;
        nx += dx[dir];
        ny += dy[dir];
    }
    
    return wireLength;
}

// DFS를 통해 모든 가능한 연결 조합 탐색
void dfs(int index, int connected, int wireLength) {
    // 모든 프로세서를 처리한 경우
    if (index == processors.size()) {
        if (connected > maxConnected) {
            maxConnected = connected;
            minWireLength = wireLength;
        }
        else if (connected == maxConnected) {
            minWireLength = min(minWireLength, wireLength);
        }
        return;
    }
    
    // 현재 프로세서의 위치
    int x = processors[index].x;
    int y = processors[index].y;
    
    // 4가지 방향으로 전선을 연결해보기
    for (int dir = 0; dir < 4; dir++) {
        if (canConnect(x, y, dir)) {
            // 전선을 연결
            int len = setConnection(x, y, dir, true);
            // DFS 재귀 호출
            dfs(index + 1, connected + 1, wireLength + len);
            // 전선을 제거 (백트래킹)
            setConnection(x, y, dir, false);
        }
    }
    
    // 현재 프로세서를 연결하지 않고 넘어가기
    dfs(index + 1, connected, wireLength);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for(int tc=1; tc<=T; tc++){
        cin >> N;
        
        // 그리드 입력 및 프로세서 목록 작성
        processors.clear();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 1){
                    if(!isEdge(i, j)){
                        processors.push_back(Processor{ i, j });
                    }
                }
            }
        }
        
        // 최대 연결 수와 최소 전선 길이 초기화
        maxConnected = 0;
        minWireLength = INT_MAX;
        memset(visitedGrid, false, sizeof(visitedGrid));
        
        // DFS 시작
        dfs(0, 0, 0);
        
        cout << "#" << tc << " " << minWireLength << "\n";
    }
    
    return 0;
}
