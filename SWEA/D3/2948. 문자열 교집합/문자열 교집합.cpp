#include <bits/stdc++.h>
using namespace std;

int T, N, M;
string B, A[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		sort(A, A + N);

		int answer = 0;

		for (int i = 0; i < M; i++) {
			cin >> B;
			if (binary_search(A, A + N, B)) {
				answer++;
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}