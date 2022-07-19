#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char board[1000][1000];
int visited[1000][1000];
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
int R, C;
int ans = 1000000;
queue<pair<int, int>> Q;
int main() {
	cin >> C >> R;
	pair<int, int> J;
	for (int i = 0; i < C; i++) {	
		for (int j = 0; j < R; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') Q.push({ i, j });
			if (board[i][j] == 'J') J = make_pair(i, j);
			if (board[i][j] == '.') visited[i][j] = -1;
		}
	}
	Q.push(J);
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= C || y < 0 || y >= R) continue;
			if (visited[x][y] >= 0) continue;
			if (board[cur.first][cur.second] == 'J') board[x][y] = 'J';

			Q.push({ x,y });
			visited[x][y] = visited[cur.first][cur.second] + 1;
		}
	}
	int errorFlag = true;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (i == 0 || i == C - 1 || j == 0 || j == R - 1) {
				if (board[i][j] == 'J') {
					errorFlag = false;
					ans = min(visited[i][j] + 1, ans);
				}
			}
		}
	}
	if (errorFlag) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << ans;
}
//불이 두 개 이상일 수도 있음.
