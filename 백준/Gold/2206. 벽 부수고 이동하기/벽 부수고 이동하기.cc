#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int map[1000][1000];
bool visited[1000][1000][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Point {
	int x, y;
	int dist;
	int broken;	// 0: 벽을 부수지 않음, 1: 벽을 부숨
};

bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int bfs() {
	queue<Point> q;
	
	visited[0][0][0] = true;
	q.push({ 0, 0, 1, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int broken = q.front().broken;
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

			if (map[nx][ny] == 0 && !visited[nx][ny][broken]) {
				visited[nx][ny][broken] = true;
				q.push({ nx, ny, dist + 1, broken });
			}
			else if (map[nx][ny] == 1 && broken == 0) {
				visited[nx][ny][1] = true;
				q.push({ nx, ny, dist + 1, 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

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