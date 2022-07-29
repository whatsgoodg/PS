//좀 색다른 생각이 필요하다.
//열 하나에 퀸 하나밖에 들어가지 못한다는 성질을 파악하고 잇어야한다.
//열 하나에 퀸 하나밖에 들어가지 못한다면, 우린 한 열마다 퀸을 행을 바꿔가며 비교를 할 것이다.
//이러한 규칙을 알고 있어야 해결할 수 있는 문제이다.
#include <iostream>
#include <utility>
#include <stack>
using namespace std;

bool board[14][14];
int dx[3]{-1, -1, -1};
int dy[3]{0,-1,1};
int N;
int ans = 0;

void func(int n) {
	if (n == N) {
		ans++;
		return;
    }
	for (int i = 0; i < N; i++){
		int x = n;
		int y = i;
		bool atkFlag = false;
		for (int j = 0; j < 3; j++) {	
			x += dx[j];
			y += dy[j];
			while (x >= 0 && y >= 0 && y < N) {
				if (board[x][y]) {
					atkFlag = 1;
					break;
				}
				x += dx[j];
				y += dy[j];
			}
			if (atkFlag) break;
			x = n;
			y = i;
		}
		if (atkFlag) continue;
		else {
			board[n][i] = 1;
			func(n + 1);
			board[n][i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	func(0);
	cout << ans;
}
