#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int board[500][500];
int visited[500][500]{};
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
int N, M;
int tnum = 0, area = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> board[i][j];

	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] && visited[i][j] == 0) {
				int cnt = 1;
				Q.push({ i, j });
				visited[i][j] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int t = 0; t < 4; t++) {
						int x = cur.X + dx[t];
						int y = cur.Y + dy[t];
						if (x < 0 || x >= N || y < 0 || y >= M) continue;
						if (visited[x][y] || !board[x][y]) continue;
						if (board[x][y]) cnt++;
						Q.push({ x,y });
						visited[x][y] = 1;
					}
				}
				tnum++;
				if (cnt > area) area = cnt;
			}
		}
	}
	cout << tnum << " " << area;
	
}
