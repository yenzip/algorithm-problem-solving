#include <iostream>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

int T, N, M;
char map[1000][1000];
int level[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
int answer;

bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isValid(nx, ny) || map[nx][ny] == 'W' || level[nx][ny] != -1) {
				continue;
			}

			q.push({ nx, ny });
			level[nx][ny] = level[x][y] + 1;
			answer += level[nx][ny];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < M; j++) {
				map[i][j] = line[j];
				if (map[i][j] == 'W') {
					level[i][j] = 0;
					q.push({ i, j });
				}
				else {
					level[i][j] = -1;
				}
			}
		}

		answer = 0;
		bfs();
		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}