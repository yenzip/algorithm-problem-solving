#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int x, y;
vector<int> graph[11];
bool visited[11];
int answer;

void dfs(int now, int dist) {
	visited[now] = true;
	answer = max(answer, dist);

	for (auto next : graph[now]) {
		if (!visited[next]) {
			dfs(next, dist + 1);
		}
	}

	visited[now] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		answer = 0;

		for (int i = 1; i <= N; i++) {
			dfs(i, 1);
		}

		cout << "#" << tc << " " << answer << "\n";

		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
	}

	return 0;
}