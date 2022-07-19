#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int board[50][50]{};
int visited[50][50]{};
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
int N;
int ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int row, col, n;
	int x, y;
	for (int t = 0; t < N; t++) {
		cin >> row >> col >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			board[x][y] = 1;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] != 1 || visited[i][j]) continue;
				queue<pair<int, int>> Q;
				Q.push({ i, j });
				visited[i][j] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int t = 0; t < 4; t++) {
						int x = cur.first + dx[t];
						int y = cur.second + dy[t];
						if (x < 0 || x >= row || y < 0 || y >= col) continue;
						if (!board[x][y] || visited[x][y]) continue;
						visited[x][y] = 1;
						Q.push({ x,y });
					}
				}
				ans++;
			}
		}
		cout << ans << "\n";
		ans = 0;
		fill(&board[0][0], &board[49][50], 0);
		fill(&visited[0][0], &visited[49][50], 0);
	}

}
