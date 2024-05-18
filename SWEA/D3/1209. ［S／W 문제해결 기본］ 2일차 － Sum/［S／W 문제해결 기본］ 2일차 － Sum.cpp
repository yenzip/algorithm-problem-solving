#include <bits/stdc++.h>
using namespace std;

int T;
int A[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> T;

		int answer = 0;

		// 각 행의 합
		for (int i = 0; i < 100; i++) {
			int row = 0;
			for (int j = 0; j < 100; j++) {
				cin >> A[i][j];
				row += A[i][j];
			}
			answer = max(answer, row);
		}

		// 각 열의 합
		for (int j = 0; j < 100; j++) {
			int col = 0;
			for (int i = 0; i < 100; i++) {
				col += A[i][j];
			}
			answer = max(answer, col);
		}

		// 각 대각선의 합
		int diagonal1 = 0, diagonal2 = 0;
		for (int i = 0; i < 100; i++) {
			diagonal1 += A[i][i];
			diagonal2 += A[i][100 - i - 1];
		}
		answer = max(answer, max(diagonal1, diagonal2));

		cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}