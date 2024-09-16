#include <iostream>
#include <queue>
using namespace std;

struct Edge {
	int u, v;
	int weight;
	bool operator<(const Edge &other) const {
		return weight > other.weight;
	}
};

int N, M;
int map[10][10];
bool visited[10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int parent[7];
priority_queue<Edge> pq;

bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs(int x, int y, int num) {
	queue<pair<int, int>> q;

	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		map[curX][curY] = num;

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (isValid(nx, ny) && map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void distance(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int dist = 0;

	while (isValid(nx, ny) && map[nx][ny] == 0) {
		nx += dx[dir];
		ny += dy[dir];
		dist++;
	}

	// 유효한 다리: 두 섬을 잇는 다리 길이가 2 이상이어야 함
	if (isValid(nx, ny) && map[nx][ny] != map[x][y] && dist >= 2) {
		pq.push({ map[x][y], map[nx][ny], dist });
	}
}

// 유니온 파인드 알고리즘
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// 1. 섬 구역 구분하기
	int island = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				bfs(i, j, ++island);
			}
		}
	}

	// 2. 섬과 섬 사이 거리 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				for (int d = 0; d < 4; d++) {
					distance(i, j, d);
				}
			}
		}
	}

	// 3. 최소 신장 트리 - 크루스칼
	for (int i = 1; i <= island; i++) {
		parent[i] = i;
	}

	int answer = 0;
	int edgeCount = 0;

	// 간선 선택 과정
	while (!pq.empty()) {
		Edge edge = pq.top();
		pq.pop();  // 간선을 처리한 후 pop 필요

		int a = edge.u;
		int b = edge.v;
		int w = edge.weight;

		// 두 섬이 아직 연결되지 않았다면 선택
		if (find(a) != find(b)) {
			merge(a, b);  // 두 섬을 연결
			answer += w;
			edgeCount++;
		}
	}

	// 모든 섬이 연결되지 않으면 -1 출력
	cout << (edgeCount == island - 1 ? answer : -1) << endl;

	return 0;
}