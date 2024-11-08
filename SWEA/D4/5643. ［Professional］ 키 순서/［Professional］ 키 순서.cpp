#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M, a, b;
vector<vector<int>> graph;
vector<vector<int>> reverseGraph;
bool visited[501];

int bfs(vector<vector<int>> &g, int start) {
	queue<int> q;
	int count = 0;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : g[now]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				count++;
			}
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		graph.assign(N + 1, vector<int>());
		reverseGraph.assign(N + 1, vector<int>());

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			reverseGraph[b].push_back(a);
		}

		int answer = 0;

		for (int i = 1; i <= N; i++) {
			memset(visited, false, sizeof(visited));
			int taller = bfs(graph, i);	// 자신(i)보다 큰 사람의 수
			memset(visited, false, sizeof(visited));
			int smaller = bfs(reverseGraph, i);	// 자신(i)보다 작은 사람의 수
			if (taller + smaller == N - 1) {
				answer++;
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}