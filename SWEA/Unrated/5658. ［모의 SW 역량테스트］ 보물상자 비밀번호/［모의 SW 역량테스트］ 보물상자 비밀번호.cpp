#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, M;
string lock;
string rotation;
set<string> pwd_set;

void rotate() {
	char temp = rotation[N - 1];
	for (int i = N - 1; i > 0; i--) {
		rotation[i] = rotation[i - 1];
	}
	rotation[0] = temp;
}

void split() {
	for (int i = 0; i < N; i += M) {
		string pwd = rotation.substr(i, M);
		pwd_set.insert(pwd);  // 중복되지 않게 set에 저장
	}
}

int hexToDec(string hex) {
	int result = 0;
	for (char c : hex) {
		if (isdigit(c)) {  // 0 ~ 9
			result = result * 16 + c - '0';
		}
		else {  // A ~ F
			result = result * 16 + c - 'A' + 10;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;

		M = N / 4;  // 한 변에서 숫자의 개수

		cin >> lock;
		rotation = lock;
		pwd_set.clear();

		// M번 회전하며 각 회전마다 비밀번호 추출
		for (int i = 0; i < M; i++) {
			split();   // 비밀번호 추출
			rotate();  // 회전
		}

		// 중복 없는 16진수 비밀번호를 모두 저장한 후, 벡터로 변환
		vector<string> pwd_vec(pwd_set.begin(), pwd_set.end());

		// 16진수 값을 내림차순으로 정렬
		sort(pwd_vec.rbegin(), pwd_vec.rend());

		// K번째로 큰 16진수 값을 10진수로 변환
		string hex = pwd_vec[K - 1];  // K번째 큰 값 (0-based 인덱스)
		int answer = hexToDec(hex);

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}