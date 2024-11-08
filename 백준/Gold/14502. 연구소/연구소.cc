#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // memset을 사용하기 위해 추가
using namespace std;

struct Point {
    int x, y;
};

int N, M;
int grid[8][8], copyGrid[8][8];
vector<Point> virus;
vector<Point> space;
vector<bool> selected;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int answer;

// 유효한 좌표인지 확인 (true: 무효, false: 유효)
bool isInvalid(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= M);
}

// 바이러스 확산을 시뮬레이션하고 감염된 칸의 수를 반환
int bfs() {
    queue<Point> q;
    bool visited[8][8];
    memset(visited, false, sizeof(visited)); // visited 배열 초기화

    int result = 0; // 빈칸 -> 바이러스로 변경된 칸의 수

    // 초기 바이러스 위치를 큐에 추가하고 방문 표시
    for (size_t i = 0; i < virus.size(); i++) {
        int x = virus[i].x;
        int y = virus[i].y;
        q.push({x, y});
        visited[x][y] = true;
    }

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInvalid(nx, ny) || visited[nx][ny] || copyGrid[nx][ny] != 0) {
                continue;
            }

            q.push({nx, ny});
            visited[nx][ny] = true;
            result++;
        }
    }

    return result;
}

// 벽을 세우고 안전 영역을 계산하여 최대 값을 업데이트
void buildWallAndCheckSafeZone() {
    memcpy(copyGrid, grid, sizeof(grid)); // grid을 copyGrid로 복사

    // 3개의 벽 세우기
    for (size_t i = 0; i < selected.size(); i++) {
        if (selected[i]) {
            int x = space[i].x;
            int y = space[i].y;
            copyGrid[x][y] = 1;
        }
    }

    // 바이러스 확산
    int count = bfs();
    int safe = static_cast<int>(space.size()) - count - 3; // 타입 캐스팅
    answer = max(answer, safe);
}

// 3개의 벽을 조합하여 안전 영역을 계산
void combination(size_t index, int depth) {
    if (depth == 3) {
        buildWallAndCheckSafeZone();
        return;
    }

    for (size_t i = index; i < space.size(); i++) {
        if (!selected[i]) {
            selected[i] = true;
            combination(i + 1, depth + 1);
            selected[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                space.push_back({i, j});
            }
            if (grid[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    // 3개의 벽을 세울 빈칸 선택
    answer = 0;
    selected.resize(space.size(), false); // 선택 여부 초기화
    combination(0, 0);

    cout << answer;

    return 0;
}
