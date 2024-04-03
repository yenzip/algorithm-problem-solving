/* 상향식 */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
int d[MAX + 1];

int main() {
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}

	cout << d[N];

	return 0;
}