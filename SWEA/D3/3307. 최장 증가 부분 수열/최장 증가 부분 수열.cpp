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

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		vector<int> LIS;
		LIS.push_back(A[0]);

		for (int i = 1; i < N; i++) {
			if (LIS.back() < A[i]) {
				LIS.push_back(A[i]);
			} else {
				int idx = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
				LIS[idx] = A[i];
			}
		}

		cout << "#" << tc << " " << LIS.size() << "\n";
	}

	return 0;
}
