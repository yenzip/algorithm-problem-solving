#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Operation {	// 회전 연산
	int r, c, s;
};

int N, M, K;
int A[51][51], copyA[51][51];
int r, c, s;
int dr[4] = { 1, 0, -1, 0 };	// 하 우 상 좌
int dc[4] = { 0, 1, 0, -1 };
vector<Operation> ops;
vector<int> idx;

bool isValid(int r, int c, int s, Operation op) {
	return (r >= op.r - s && r <= op.r + s && c >= op.c - s && c <= op.c + s);
}

void rotate(Operation op) {
	for (int i = 1; i <= op.s; i++) {
		int r = op.r - i;
		int c = op.c - i;
		int temp = A[r][c];
		int dir = 0;

		while (dir < 4) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (!isValid(nr, nc, i, op)) {
				dir++;
				continue;
			}

			A[r][c] = A[nr][nc];
			r = nr;
			c = nc;
		}
		A[r][c + 1] = temp;
	}
}

int calculate() {
	int result = INT_MAX;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += A[i][j];
		}
		result = min(result, sum);
	}
	return result;
}

void copyArray() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			A[i][j] = copyA[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> copyA[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		ops.push_back({ r, c, s });
		idx.push_back(i);
	}

	int answer = INT_MAX;

	do {
		copyArray();
		for (int i = 0; i < idx.size(); i++) {
			rotate(ops[idx[i]]);
		}
		answer = min(answer, calculate());
	} while (next_permutation(idx.begin(), idx.end()));

	cout << answer;

	return 0;
}