#include <bits/stdc++.h>
using namespace std;

int T;
string C, S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> T >> C >> S;

		int answer = 0;

		for (int i = 0; i <= S.size() - C.size(); i++) {
			string sub = S.substr(i, C.size());

			if (sub == C) {
				answer++;
			}
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}