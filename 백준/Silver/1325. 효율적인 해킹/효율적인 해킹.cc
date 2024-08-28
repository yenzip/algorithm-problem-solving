#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M, a, b;
vector<vector<int>> graph;
bool visited[10001];

int bfs(int start) {
	queue<int> q;
	int cnt = 0;	// 해킹할 수 있는 컴퓨터의 수

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		cnt++;
		q.pop();

		for (int next : graph[now]) {
			if (visited[next]) {
				continue;
			}
			visited[next] = true;
			q.push(next);
		}
	}

	return cnt - 1;	// 본인(start) 제외
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[b].push_back(a);
	}

	int hacking[10001];
	int maxCount = 0;	// 최대 컴퓨터 해킹 개수
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		hacking[i] = bfs(i);
		maxCount = max(maxCount, hacking[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (hacking[i] == maxCount) {
			cout << i << "\n";
		}
	}

	return 0;
}