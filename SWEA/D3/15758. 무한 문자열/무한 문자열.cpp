#include <bits/stdc++.h>
using namespace std;

int T;
string A, B;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

string repeat_string(string s, int cnt) {
	string result;

	for (int i = 0; i < cnt; i++) {
		result += s;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> A >> B;

		int a = A.size();
		int b = B.size();

		int lcm = a * b / gcd(a, b);

		string infA = repeat_string(A, lcm / a);
		string infB = repeat_string(B, lcm / b);
		string answer = infA == infB ? "yes" : "no";

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}