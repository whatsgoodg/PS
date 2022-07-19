#include <iostream>
#include <queue>
using namespace std;

int board[100001];
int visited[100001];
int dx[3]{ 1,-1,2 };
int N, K;
queue<int> Q;
int ans = 100001;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	Q.push(N);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < 3; i++) {
			int x;
			if (i == 2) x = cur * dx[i];
			else x = cur + dx[i];
			if (x > 100000 || x < 0) continue;
			if (visited[x] > 0 && x != K) continue;
			Q.push(x);
			visited[x] = visited[cur] + 1;
			if (x == K) {
				cout << visited[x];
				return 0;
			}
		}
	}
}
