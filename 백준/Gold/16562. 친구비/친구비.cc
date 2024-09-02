#include <iostream>
#include <set>
using namespace std;

int N, M, k, v, w;
int A[10001];
int parent[10001];

// 대표 노드 찾기
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
		if (A[a] <= A[b]) {
			parent[b] = a;
		}
		else {
			parent[a] = b;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> v >> w;
		merge(v, w);
	}

	set<int> st;
	for (int i = 1; i <= N; i++) {
		st.insert(find(i));
	}

	int cost = 0;
	for (int idx : st) {
		cost += A[idx];
	}

	if (cost > k) {
		cout << "Oh no";
	}
	else {
		cout << cost;
	}

	return 0;
}