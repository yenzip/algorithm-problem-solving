#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct info {
	int x, y;
	int dist;
	
	bool operator<(const info &other) const {
		return dist > other.dist;
	}
};

int T, N;
int map[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInvalid(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}

int bfs() {
	priority_queue<info> pq;
	memset(visited, false, sizeof(visited));

	visited[0][0] = true;
	pq.push({0, 0, 0});

	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int dist = pq.top().dist;
		pq.pop();

		if (x == N - 1 && y == N - 1) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInvalid(nx, ny) || visited[nx][ny]) {
				continue;
			}

			visited[nx][ny] = true;
			pq.push({ nx, ny, dist + map[nx][ny]});
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < N; j++) {
				map[i][j] = line[j] - '0';
			}
		}

		int answer = bfs();
		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}