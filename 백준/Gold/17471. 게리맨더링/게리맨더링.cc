#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int N, x, v;
int people[11];
vector<vector<int>> graph;
bool visited[11];
vector<int> group1, group2;
int answer;

int dfs(vector<int> group, int now) {
	visited[now] = true;
	int ret = 1;

	for (int next : graph[now]) {
		for (int i = 0; i < group.size(); i++) {
			if (next == group[i] && !visited[next]) {
				ret += dfs(group, next);
			}
		}
	}

	return ret;
}

bool check(vector<int> group) {
	if (group.size() == 0 || group.size() == N) {
		return false;
	}
	memset(visited, false, sizeof(visited));
	return group.size() == dfs(group, group[0]);
}

int calculate(vector<int> group) {
	int sum = 0;
	for (int node : group) {
		sum += people[node];
	}
	return sum;
}

void combination(int node) {	
	if (node > N) {
		if (check(group1) && check(group2)) {
			int res1 = calculate(group1);
			int res2 = calculate(group2);
			answer = min(answer, abs(res1 - res2));
		}
		return;
	}

	// 해당 정점 Group1 선택
	group1.push_back(node);
	combination(node + 1);
	group1.pop_back();

	// 해당 정점 Group2 선택
	group2.push_back(node);
	combination(node + 1);
	group2.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}

	graph.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> x;	// graph[i]의 사이즈
		for (int j = 0; j < x; j++) {
			cin >> v;
			graph[i].push_back(v);
		}
	}

	answer = INT_MAX;
	combination(1);
	
	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}