#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
	int left;
	int right;
	int count;
};

int T, N, X, M;
int l, r, s;
vector<Record> records;
vector<int> cages;
vector<int> sum;	// 누적합
vector<int> answer;
int max_count;

void permutation(int num) {
	if (num > N) {
		// 모든 기록을 만족하는지 확인
		for (const Record& r : records) {
			if (sum[r.right] - sum[r.left - 1] != r.count) {
				return;
			}
		}
		if (max_count < sum[N]) {
			max_count = sum[N];
			answer = cages;
		}
		return;
	}

	for (int i = 0; i <= X; i++) {
		cages[num] = i;
		sum[num] = sum[num - 1] + i;
		permutation(num + 1);
		sum[num] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> X >> M;

		records.clear();

		for (int i = 0; i < M; i++) {
			cin >> l >> r >> s;
			records.push_back({ l, r, s });
		}

		max_count = -1;
		cages.assign(N + 1, 0);
		sum.assign(N + 1, 0);
		answer.clear();

		permutation(1);

		if (max_count == -1) {
			cout << "#" << tc << " " << -1 << "\n";
			continue;
		}

		cout << "#" << tc << " ";
		for (int i = 1; i <= N; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
