#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

int N, cnt, num;
int people[11];
bool adjMatrix[11][11];	// 인접 행렬
bool selected[11];
bool visited[11];
int answer;

int dfs(vector<int> &g, int now) {
	visited[now] = true;
	int ret = 1;

	for (int next = 1; next <= N; next++) {
		if (adjMatrix[now][next] && !visited[next] && find(g.begin(), g.end(), next) != g.end()) {
			ret += dfs(g, next);
		}
	}

	return ret;
}

bool isConnected(vector<int> &g) {
	if (g.size() == 0 || g.size() == N) {
		return false;
	}
	memset(visited, false, sizeof(visited));
	return g.size() == dfs(g, g[0]);
}

void divideGroupsAndCheckDiff() {
	vector<int> A, B;
	int sumA = 0, sumB = 0;

	for (int i = 1; i <= N; i++) {
		if (selected[i]) {
			A.push_back(i);
			sumA += people[i];
		}
		else {
			B.push_back(i);
			sumB += people[i];
		}
	}

	if (isConnected(A) && isConnected(B)) {
		answer = min(answer, abs(sumA - sumB));
	}
}

void combination(int num) {
	if (num > N) {
		divideGroupsAndCheckDiff();
		return;
	}

	// 선택 O
	selected[num] = true;
	combination(num + 1);

	// 선택 X
	selected[num] = false;
	combination(num + 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> people[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> num;
			adjMatrix[i][num] = true;
		}
	}

	answer = INT_MAX;
	combination(1);

	cout << (answer == INT_MAX ? -1 : answer);

	return 0;
}