#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[1000];

bool isIncreased(string s) {
	int max_idx = 0;

	for (int i = 1; i < s.size(); i++) {
		if (s[max_idx] > s[i]) {
			return false;
		} 
		max_idx = i;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		int answer = -1;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int x = A[i] * A[j];

				if (isIncreased(to_string(x))) {
					answer = max(answer, x);
				}
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}