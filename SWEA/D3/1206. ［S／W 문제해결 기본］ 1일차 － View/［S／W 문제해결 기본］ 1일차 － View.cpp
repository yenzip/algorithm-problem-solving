#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000];

bool check(int idx) {
	int max_idx = max_element(A + idx - 2, A + idx + 3) - A;
	return max_idx == idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		int answer = 0;

		for (int i = 2; i < N - 2; i++) {
			if (check(i)) {	// i번째 빌딩이 가장 높다면
				int max2 = max(max(A[i - 2], A[i - 1]), max(A[i + 1], A[i + 2]));	// 양쪽 중 2번째로 큰 빌딩 구하기
				answer += A[i] - max2;
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}