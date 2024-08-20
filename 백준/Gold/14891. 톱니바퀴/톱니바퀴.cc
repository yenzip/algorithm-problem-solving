#include <bits/stdc++.h>
using namespace std;

int K, number, direction;
int A[5][8];	// 톱니바퀴
int isRotation[5];

void rotation(int number, int direction) {
	if (direction == -1) {	// 반시계 방향
		int tmp = A[number][0];
		for (int i = 0; i < 7; i++) {
			A[number][i] = A[number][i + 1];
		}
		A[number][7] = tmp;
	}
	else {	// 시계 방향
		int tmp = A[number][7];
		for (int i = 7; i > 0; i--) {
			A[number][i] = A[number][i - 1];
		}
		A[number][0] = tmp;
	}
}

void leftCheck(int number, int direction) {
	if (number <= 1) {
		return;
	}
	if (A[number - 1][2] != A[number][6]) {
		isRotation[number - 1] = direction * -1;
		leftCheck(number - 1, direction * -1);
	}
}

void rightCheck(int number, int direction) {
	if (number >= 4) {
		return;
	}
	if (A[number][2] != A[number + 1][6]) {
		isRotation[number + 1] = direction * -1;
		rightCheck(number + 1, direction * -1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 4; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < 8; j++) {
			A[i][j] = line[j] - '0';
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> number >> direction;

		memset(isRotation, 0, sizeof(isRotation));

		isRotation[number] = direction;

		leftCheck(number, direction);
		rightCheck(number, direction);

		for (int j = 1; j <= 4; j++) {
			if (isRotation[j] != 0) {
				rotation(j, isRotation[j]);
			}
		}
	}

	int answer = 0;
	int score = 1;

	for (int i = 1; i <= 4; i++) {
		if (A[i][0] == 1) {
			answer += score;
		}
		score *= 2;
	}

	cout << answer;
	
    return 0;
}