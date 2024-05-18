#include <bits/stdc++.h>
using namespace std;

int T, N;
string C, S;
map<string, int> m = {
	{"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR", 3}, {"FOR", 4},
	{"FIV", 5}, {"SIX", 6}, {"SVN", 7}, {"EGT", 8}, {"NIN", 9}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> C >> N;

		priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

		for (int i = 0; i < N; i++) {
			cin >> S;
			pq.push({ m[S], S });
		}

		cout << "#" << tc << "\n";
		while (!pq.empty()) {
			cout << pq.top().second << " ";
			pq.pop();
		}
		cout << "\n";
	}

	return 0;
}