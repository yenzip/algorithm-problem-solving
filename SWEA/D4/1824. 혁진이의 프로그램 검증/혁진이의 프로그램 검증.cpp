#include <iostream>
#include <cstring>
using namespace std;

int T, R, C;
char grid[20][20];
bool visited[20][20][16][4];
int dx[4] = { 0, 0, -1, 1 };	// 좌 우 상 하
int dy[4] = { -1, 1, 0, 0 };
bool isExit;

void dfs(int x, int y, int memory, int dir) {
	if (isExit) {
		return;
	}

	// x, y가 격자 바깥이라면, 반대편 위치로 이동
	if (x < 0) x = R - 1;
	if (x >= R) x = 0;
	if (y < 0) y = C - 1;
	if (y >= C) y = 0;

	// 현재 상태가 이미 방문한 상태라면 탐색 중단
	if (visited[x][y][memory][dir]) return;
	visited[x][y][memory][dir] = true;

	char cmd = grid[x][y];

	// 종료 명령어를 만났다면, 탐색 종료
	if (cmd == '@') {
		isExit = true;
		return;
	}

	// 명령어 처리
	switch (cmd) {
	case '<': 
		dir = 0;
		break;
	case '>':
		dir = 1;
		break;
	case '^':
		dir = 2;
		break;
	case 'v':
		dir = 3;
		break;
	case '_':
		dir = (memory == 0 ? 1 : 0);
		break;
	case '|':
		dir = (memory == 0 ? 3 : 2);
		break;
	case '.':
		break;
	case '+':
		memory = (memory == 15 ? 0 : memory + 1);
		break;
	case '-':
		memory = (memory == 0 ? 15 : memory - 1);
		break;
	default:
		if (isdigit(cmd)) {
			memory = cmd - '0';
			break;
		}
	}

	if (cmd == '?') {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			dfs(nx, ny, memory, i);
		}
	}
	else {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		dfs(nx, ny, memory, dir);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> R >> C;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> grid[i][j];
			}
		}

		isExit = false;
		memset(visited, false, sizeof(visited));
		dfs(0, 0, 0, 1);	// 시작 좌표 (0,0), 메모리 0, 방향 우 (1)

		cout << "#" << tc << " " << (isExit ? "YES\n" : "NO\n");
	}
	
	return 0;
}