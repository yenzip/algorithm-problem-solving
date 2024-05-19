#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	cin.ignore();	// 문자열 입력 전, 버퍼 비워주기

	for (int tc = 1; tc <= T; tc++) {
		getline(cin, S);

		string answer;
		stringstream ss(S);
		string s1, s2, s3;
		ss >> s1 >> s2 >> s3;

		answer += toupper(s1[0]);
		answer += toupper(s2[0]);
		answer += toupper(s3[0]);

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}