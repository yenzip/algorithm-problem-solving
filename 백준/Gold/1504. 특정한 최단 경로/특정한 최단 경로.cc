#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, E;
int a, b, c, v1, v2;
vector<vector<pair<int, int>>> graph;
int dist[801];	// dist[i]: i 정점까지 최단거리

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(dist, dist + N + 1, INT_MAX);

	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int now = pq.top().second;	    // 현재 거리
		int now_dist = pq.top().first;	// 현재 노드
		pq.pop();

		if (now_dist > dist[now]) {	// 최단 거리보다 더 긴 거리라면 무시
			continue;
		}

		for (auto edge : graph[now]) {
			int next = edge.second;
			int cost = edge.first;

			if (dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	graph.resize(N + 1);

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	cin >> v1 >> v2;

	// 1. 1 정점에서 v1, v2까지 최단 거리
	dijkstra(1);
	int s_to_v1 = dist[v1];
	int s_to_v2 = dist[v2];

	// 2. v1 정점에서 v2, N까지 최단 거리
	dijkstra(v1);
	int v1_to_v2 = dist[v2];
	int v1_to_e = dist[N];

	// 3. v2 정점에서 N까지 최단 거리
	dijkstra(v2);
	int v2_to_e = dist[N];

	// 경로 1 → v1 → v2 → N 및 1 → v2 → v1 → N 중 최단 경로 계산
	int path1 = (s_to_v1 == INT_MAX || v1_to_v2 == INT_MAX || v2_to_e == INT_MAX)
		? INT_MAX
		: s_to_v1 + v1_to_v2 + v2_to_e;
	int path2 = (s_to_v2 == INT_MAX || v1_to_v2 == INT_MAX || v1_to_e == INT_MAX)
		? INT_MAX
		: s_to_v2 + v1_to_v2 + v1_to_e;

	// 두 경로 중 최단 경로 선택
	int answer = min(path1, path2);
	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}