#include <iostream>
#include <algorithm>
using namespace std;

int T, N, K;
int map[8][8];
bool visited[8][8];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result;

bool isValid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int dist, bool cutable) {
	result = max(result, dist);

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isValid(nx, ny) || visited[nx][ny]) {
			continue;
		}

		if (map[x][y] > map[nx][ny]) {
			dfs(nx, ny, dist + 1, cutable);
		}
		// 아직 깎지 않았다면
		else if (cutable) {
			for (int k = 1; k <= K; k++) {
				if (map[x][y] > map[nx][ny] - k) {
					map[nx][ny] -= k;
					dfs(nx, ny, dist + 1, false);
					map[nx][ny] += k;
				}
			}
		}
	}

	visited[x][y] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;

		int summit = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				summit = max(summit, map[i][j]);
			}
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == summit) {
					result = 0;
					dfs(i, j, 1, true);
					answer = max(answer, result);
				}
			}
		}

		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}