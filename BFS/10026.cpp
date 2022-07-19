#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char board[100][100]{};
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
int N;
int ans = 0;
queue<pair<int, int>> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	char a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			board[i][j] = a;
		}
	}
	for (int k = 0; k < 2; k++) {
		int visited[100][100]{};

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				Q.push({ i,j });
				visited[i][j] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int t = 0; t < 4; t++) {
						int x = cur.first + dx[t];
						int y = cur.second + dy[t];
						if (x < 0 || x >= N || y < 0 || y >= N) continue;
						if (visited[x][y] || board[x][y] != board[cur.first][cur.second]) continue;
						Q.push({ x,y });
						visited[x][y] = 1;
					}
				}
				ans++;
			}
		}
		cout << ans << " ";
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}
}
