#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[100][100];
int visited[100][100]{};
int dx[4]{ 0, 1, 0, -1 };
int dy[4]{ 1, 0, -1, 0 };
int N, M;
int ans = 10000;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		for (int j = 0; j < M; j++) board[i][j] = in[j] - 48;
	}
	queue<pair<pair<int, int>, int>> Q;
	Q.push({{ 0,0 }, 1});
	visited[0][0] = 1;

	while (!Q.empty()) {
		pair<pair<int, int>, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur.first.first + dx[i];
			int y = cur.first.second + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= M) continue;
			if (visited[x][y] || !board[x][y]) continue;
			if (x == N - 1 && y == M - 1) {
				if (ans > cur.second + 1) ans = cur.second + 1;
			}
			visited[x][y] = 1;
			Q.push({ {x,y}, cur.second + 1 });
		}
	}

	cout << ans;
}
