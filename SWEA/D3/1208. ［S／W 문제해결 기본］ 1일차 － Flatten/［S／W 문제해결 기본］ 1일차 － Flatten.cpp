#include <bits/stdc++.h>
using namespace std;

int N;
int A[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;

		for (int i = 0; i < 100; i++) {
			cin >> A[i];
		}

		while (N--) {
			sort(A, A + 100);
			A[0]++;
			A[99]--;
		}

		sort(A, A + 100);
		int answer = A[99] - A[0];

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}