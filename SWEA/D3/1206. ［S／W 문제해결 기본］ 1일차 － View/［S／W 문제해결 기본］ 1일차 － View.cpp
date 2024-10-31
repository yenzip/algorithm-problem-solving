#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int heights[1000];

int check(int idx) {
	if (heights[idx] < heights[idx - 1] || heights[idx] < heights[idx + 1] || heights[idx] < heights[idx - 2] || heights[idx] < heights[idx + 2]) {
		return -1;
	}
	return min(min(heights[idx] - heights[idx - 1], heights[idx] - heights[idx + 1]), min(heights[idx] - heights[idx - 2], heights[idx] - heights[idx + 2]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {
		int answer = 0;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> heights[i];
		}

		for (int i = 2; i < N - 2; i++) {
			int res = check(i);
			if (res == -1) {
				continue;
			}
			answer += res;
		}

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}