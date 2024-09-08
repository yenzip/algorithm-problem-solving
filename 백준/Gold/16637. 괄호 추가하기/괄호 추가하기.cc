#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N;
string expression;
vector<int> nums;
vector<char> ops;
bool bracket[9];
int answer;

int calculate(int num1, int num2, char op) {
	switch (op) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	}
}

int solve() {
	queue<int> num_q;
	queue<char> op_q;

	// 괄호 먼저 연산
	int i = 0;
	while (i < ops.size()) {
		if (bracket[i]) {
			int res = calculate(nums[i], nums[i + 1], ops[i]);
			num_q.push(res);
			if (i + 1 < ops.size()) {
				op_q.push(ops[i + 1]);
			}
			i++;
		}
		else {
			num_q.push(nums[i]);
			op_q.push(ops[i]);
		}
		i++;
	}
	if (i == nums.size() - 1) {
		num_q.push(nums[i]);
	}

	int result = num_q.front();
	num_q.pop();

	while (!op_q.empty()) {
		int num = num_q.front();
		char op = op_q.front();
		num_q.pop();
		op_q.pop();
		result = calculate(result, num, op);
	}

	return result;
}

void combination(int index) {
	if (index >= ops.size()) {
		answer = max(answer, solve());
		return;
	}

	// 괄호 적용 O
	bracket[index] = true;
	combination(index + 2);

	// 괄호 적용 X
	bracket[index] = false;
	combination(index + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> expression;

	for (int i = 0; i < N; i++) {
		if (isdigit(expression[i])) {
			nums.push_back(expression[i] - '0');
		}
		else {
			ops.push_back(expression[i]);
		}
	}

	answer = INT_MIN;
	combination(0);

	cout << answer;
	
	return 0;
}