#include <iostream>
#include <set>
using namespace std;

int T, N, M, a, b;
int parent[101];

// 대표 노드 찾아 반환하기
int find(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find(parent[x]);
}

// 두 집합 합치기
void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			merge(a, b);
		}

		set<int> st;
		for (int i = 1; i <= N; i++) {
			st.insert(find(i));
		}

		cout << "#" << tc << " " << st.size() << endl;
	}

	return 0;
}