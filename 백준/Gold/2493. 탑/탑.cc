#include <bits/stdc++.h>
using namespace std;

int N;
int A[500001];
int answer[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	stack<int> stk;

	for (int i = N; i > 0; i--) {
		while (!stk.empty() && A[stk.top()] < A[i]) {
			answer[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}