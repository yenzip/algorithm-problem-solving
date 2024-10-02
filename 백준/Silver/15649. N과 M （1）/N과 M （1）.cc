#include <iostream>
#include <vector>
using namespace std;

int N, M;
int selected[8];
bool visited[9];

void print() {
	for (int i = 0; i < M; i++) {
		cout << selected[i] << " ";
	}
	cout << "\n";
}

void perm(int index) {
	if (index == M) {
		print();
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			selected[index] = i;
			perm(index + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	perm(0);
	
	return 0;
}