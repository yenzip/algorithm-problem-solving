#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		map<int, int> m;
		int max_cnt = 0;

		for (int i = 0; i < 1000; i++) {
			cin >> A[i];
			m[A[i]]++;
			max_cnt = max(max_cnt, m[A[i]]);
		}

		int answer = 0;

		for (auto it : m) {
			if (it.second == max_cnt) {
				answer = max(answer, it.first);
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}