#include <bits/stdc++.h>
using namespace std;

int N;
int T[15];
int P[15];
int answer = 0;

void dfs(int start, int cost) {
	if (start > N) {
		return;
	}

	answer = max(answer, cost);

	for (int i = start; i < N; i++) {
		dfs(i + T[i], cost + P[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(0, 0);

	cout << answer << '\n';

	return 0;
}