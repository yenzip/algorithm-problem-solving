#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int x, y;
	int count;
	int k;	// 말의 움직임 사용 횟수
};

int K, W, H;
int map[200][200];
bool visited[200][200][31];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int hdx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hdy[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

bool isValid(int x, int y) {
	return (x >= 0 && x < W && y >= 0 && y < H);
}

int bfs() {
	queue<Info> q;

	visited[0][0][0] = true;
	q.push({ 0, 0, 0, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int count = q.front().count;
		int k = q.front().k;
		q.pop();

		if (x == W - 1 && y == H - 1) {
			return count;
		}

		if (k < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hdx[i];
				int ny = y + hdy[i];

				if (!isValid(nx, ny) || map[nx][ny] == 1 || visited[nx][ny][k + 1]) {
					continue;
				}

				visited[nx][ny][k + 1] = true;
				q.push({ nx, ny, count + 1, k + 1 });
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isValid(nx, ny) || map[nx][ny] == 1 || visited[nx][ny][k]) {
				continue;
			}

			visited[nx][ny][k] = true;
			q.push({ nx, ny, count + 1, k });
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> H >> W;

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs();

	return 0;
}