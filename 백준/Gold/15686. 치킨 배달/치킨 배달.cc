#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Point {
	int x, y;
};

int N, M;
int grid[50][50];
vector<Point> homes;
vector<Point> chicken;
int selected[13];
bool visited[13];
int answer;

// 집과 치킨집 사이 거리
int checkDistance() {
	int dist = 0;

	for (int i = 0; i < homes.size(); i++) {
		int hx = homes[i].x;
		int hy = homes[i].y;
		int min_dist = INT_MAX;
		for (int j = 0; j < M; j++) {
			int cx = chicken[selected[j]].x;
			int cy = chicken[selected[j]].y;

			min_dist = min(min_dist, abs(hx - cx) + abs(hy - cy));
		}
		dist += min_dist;
	}

	return dist;
}

void combination(int index, int depth) {
	if (depth == M) {
		answer = min(answer, checkDistance());
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		selected[depth] = i;
		combination(i + 1, depth + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				homes.push_back({ i, j });
			}
			if (grid[i][j] == 2) {
				chicken.push_back({ i, j });
			}
		}
	}

	answer = INT_MAX;
	combination(0, 0);

	cout << answer;

	return 0;
}