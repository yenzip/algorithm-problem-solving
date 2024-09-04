#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Info {
	int x, y;
	int dist;
	int k;	// 벽을 부순 개수
};

int N, M, K;
int map[1000][1000];
bool visited[1000][1000][11];	// 최대 10개의 벽을 부술 수 있음
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int bfs() {
	queue<Info> q;

	visited[0][0][0] = true;
	q.push({ 0, 0, 1, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int k = q.front().k;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isValid(nx, ny)) {
				continue;
			}

			// 벽이 아니고 아직 방문하지 않았다면
			if (map[nx][ny] == 0 && !visited[nx][ny][k]) {
				visited[nx][ny][k] = true;
				q.push({ nx, ny, dist + 1, k });
			}
			// 벽이고, 아직 벽을 부술 수 있고, 아직 방문하지 않았다면
			else if (map[nx][ny] == 1 && k < K && !visited[nx][ny][k + 1]) {
				visited[nx][ny][k + 1] = true;
				q.push({ nx, ny, dist + 1, k + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	cout << bfs();

	return 0;
}