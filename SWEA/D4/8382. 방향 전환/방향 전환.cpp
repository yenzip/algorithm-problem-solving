#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	int move;
	int dir;	// 가로(-1), 세로(1)
	Point(int px, int py, int pmove, int pdir) : x(px), y(py), move(pmove), dir(pdir) {}
};

int T;
int dx[4] = { -1, 0, 1, 0 };	// 상 좌 하 우
int dy[4] = { 0, -1, 0, 1 };

bool isInvalid(int x, int y) {
	return x < -100 || x > 100 || y < -100 || y > 100;
}

int bfs(int x1, int y1, int x2, int y2, int dir) {
	queue<Point> q;
	bool visited[201][201];
	memset(visited, false, sizeof(visited));

	q.push(Point(x1, y1, 0, dir));
	visited[x1 + 100][y1 + 100] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int move = q.front().move;
		int dir = q.front().dir;
		q.pop();

		if (x == x2 && y == y2) {
			return move;
		}

		int index = (dir == 1 ? 0 : 1);
		for (int i = index; i < 4; i += 2) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isInvalid(nx, ny) || visited[nx + 100][ny + 100]) {
				continue;
			}

			visited[nx + 100][ny + 100] = true;
			q.push(Point(nx, ny, move + 1, dir * -1));
		}
		
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int hor = bfs(x1, y1, x2, y2, -1);
		int ver = bfs(x1, y1, x2, y2, 1);

		cout << "#" << tc << " " << min(hor, ver) << "\n";
	}

	return 0;
}