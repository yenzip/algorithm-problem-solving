#include <iostream>
#include <vector>
using namespace std;

int N;
int map[16][16];
int dx[3] = { 0, 1, 1 };	// 가로, 세로, 대각선 방향
int dy[3] = { 1, 0, 1 };
vector<vector<int>> direction;
int answer;

bool isValid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int dir) {
	if (x == N - 1 && y == N - 1) {
		answer++;
		return;
	}

	for (int d : direction[dir]) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (!isValid(nx, ny) || map[nx][ny] == 1) {	
			continue;
		}

		// 대각선인 경우 가로, 세로도 추가 확인
		if (d == 2) {
			if (map[x + 1][y] == 1 || map[x][y + 1] == 1) {
				continue;
			}
		}

		dfs(nx, ny, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	direction = {
		{0, 2},     // direction[0]: 가로 -> 가로 or 대각선
		{1, 2},     // direction[1]: 세로 -> 세로 or 대각선
		{0, 1, 2}   // direction[2]: 대각선 -> 가로, 세로, 대각선
	};

	answer = 0;
	dfs(0, 1, 0);  // 초기 위치 (0, 1)에서 가로 방향 (0) 시작

	cout << answer;

	return 0;
}