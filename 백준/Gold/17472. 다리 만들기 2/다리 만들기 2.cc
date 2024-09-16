#include <iostream>
#include <tuple>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[10][10];
bool visited[10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
typedef tuple<int, int, int> edge;
set<edge> st;
int parent[7];

bool isValid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void dfs(int x, int y, int num) {
	if (visited[x][y]) {
		return;
	}

	visited[x][y] = true;
	map[x][y] = num;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!isValid(nx, ny) || !map[nx][ny]) {
			continue;
		}

		dfs(nx, ny, num);
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

	if (!isValid(nx, ny) || map[nx][ny] == map[x][y] || dist < 2) {
		return;
	}

	st.insert(make_tuple(map[x][y], map[nx][ny], dist));
}

bool compare(const edge &a, const edge &b) {
	return get<2>(a) < get<2>(b);
}

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

	// 1. 섬 구역 분리하기
	int island = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				dfs(i, j, island++);
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
	for (int i = 1; i < island; i++) {
		parent[i] = i;
	}

	vector<edge> edges(st.begin(), st.end());
	
	sort(edges.begin(), edges.end(), compare);

	int answer = 0;
	int edgeCount = 0;
	for (edge e : edges) {
		int a = get<0>(e);
		int b = get<1>(e);
		int w = get<2>(e);

		if (find(a) != find(b)) {
			merge(a, b);
			answer += w;
			edgeCount++;
		}
	}

	cout << (edgeCount == island - 2 ? answer : -1);

	return 0;
}