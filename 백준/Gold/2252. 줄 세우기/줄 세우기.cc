#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> indegree;

void topology_sort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		cout << now << " ";
		q.pop();

		for (auto next : graph[now]) {
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	graph.resize(N + 1);
	indegree.resize(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		indegree[B]++;
	}

	topology_sort();

	return 0;
}