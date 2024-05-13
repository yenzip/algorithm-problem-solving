#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for(int tc = 1; tc <= T; tc++) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> A[i];
		}

		long long answer = 0;
		int max_val = A[N];

		for (int i = N - 1; i > 0; i--) {
			if (A[i] <= max_val) {
				answer += max_val - A[i];
			} else {
				max_val = A[i];
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}