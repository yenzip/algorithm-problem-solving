#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K, X, a, b;
vector<vector<int>> graph;
bool visited[300001];
vector<int> answer;

void bfs() {
	queue<pair<int, int>> q;

	visited[X] = true;
	q.push({ X, 0 });

	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (dist == K) {
			answer.push_back(now);
			continue;
		}

		for (int next : graph[now]) {
			if (visited[next]) {
				continue;
			}
			visited[next] = true;
			q.push({ next, dist + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> X;

	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}

	bfs();

	if (answer.empty()) {
		cout << -1;
		return 0;
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}