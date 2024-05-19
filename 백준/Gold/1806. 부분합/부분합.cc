#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int N, S;
int A[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int start = 0;
	int end = 0;
	long long sum = 0;
	int answer = MAX;

	while (end <= N) {
		if (sum >= S) {
			answer = min(answer, end - start);
			sum -= A[start++];
		} else {
			sum += A[end++];
		}
	}

	if (answer == MAX) {
		answer = 0;
	}

	cout << answer;

	return 0;
}