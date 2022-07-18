#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1000][1000];
int visited[1000][1000]{};
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };
int M, N;
int ans = -1;

queue<pair<int, int>> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				cnt++;
				Q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	while (!Q.empty()) {
		int cnt2 = 0;
		for (int i = 0; i < cnt; i++) {
			if (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int j = 0; j < 4; j++) {
					int x = cur.first + dx[j];
					int y = cur.second + dy[j];
					if (x < 0 || x >= M || y < 0 || y >= N) continue;
					if (visited[x][y] || board[x][y] != 0) continue;
					visited[x][y] = 1;
					board[x][y] = 1;
					Q.push({ x,y });
					cnt2++;

				}
			}
		}
		ans++;
		cnt = cnt2;
		
	}
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			if (board[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
	cout << ans;
}
