#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
	int l;
	int r;
	int s;
};

struct Info {
	vector<int> cages;
	int sum;
};

int T, N, X, M;
int l, r, s;
vector<Record> records;
vector<int> cages;
vector<int> sum;	// 누적합
vector<Info> candidates;
int max_count;

bool check() {
	for (Record r : records) {
		int left = r.l;
		int right = r.r;
		int count = r.s;

		if (sum[right] - sum[left - 1] != count) {
			return false;
		}
	}

	return true;
}

void permutation(int num) {
	if (num > N) {
		if (check()) {
			candidates.push_back({ cages, sum[N] });
			max_count = max(max_count, sum[N]);
		}
		check();
		return;
	}

	for (int i = 0; i <= X; i++) {
		cages[num] = i;
		sum[num] = sum[num - 1] + i;
		permutation(num + 1);
		sum[num] = 0;
	}
}

bool cmp(const Info &a, const Info &b) {
	return a.cages < b.cages;
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

		max_count = 0;
		cages.assign(N + 1, 0);
		sum.assign(N + 1, 0);
		candidates.clear();

		permutation(1);

		if (candidates.size() == 0) {
			cout << "#" << tc << " " << -1 << "\n";
			continue;
		}

		vector<int> answer;

		sort(candidates.begin(), candidates.end(), cmp);

		for (Info candidate : candidates) {
			if (candidate.sum == max_count) {
				answer = candidate.cages;
				break;
			}
		}

		cout << "#" << tc << " ";
		for (int i = 1; i <= N; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
