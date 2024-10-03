#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};

int N, P, L, M, x;
string cmd;
vector<pair<int, int>> problems;	// { 난이도, 문제 번호 }
map<int, vector<int>> num;

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		problems.push_back({ L, P });
		num[P].push_back(L);
	}

	sort(problems.begin(), problems.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "recommend") {
			cin >> x;

			if (x == -1) {
				cout << problems.front().second << "\n";
			}
			else if (x == 1) {
				cout << problems.back().second << "\n";
			}
		}
		else if (cmd == "add") {
			cin >> P >> L;
			pair<int, int> new_problem = { L, P };

			auto it = lower_bound(problems.begin(), problems.end(), new_problem,
				[](const pair<int, int>& a, const pair<int, int>& b) -> bool {
					if (a.first == b.first) {
						return a.second < b.second;
					}
					return a.first < b.first;
				}
			);

			problems.insert(it, new_problem);

			num[P].push_back(L);
		}
		else if (cmd == "solved") {
			cin >> P;

			for (int i = 0; i < num[P].size(); i++) {
				pair<int, int> solve_problem = { num[P][i], P };
				auto it = lower_bound(problems.begin(), problems.end(), solve_problem);
				problems.erase(it);
			}

			num.erase(P);
		}
	}

	return 0;
}