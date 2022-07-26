#include <iostream>
#include <utility>
#include <stack>
using namespace std;

bool board[14][14];
bool straight[14];
bool Rdiagonal[27];
bool Ldiagonal[27];
int N;
int ans = 0;

void func(int n) {
	if (n == N) {
		ans++;
		return;

	}
	for (int i = 0; i < N; i++) {
		if (straight[i] || Rdiagonal[n + i] || Ldiagonal[n - i + N - 1]) continue;
		straight[i] = 1;
		Rdiagonal[n + i] = 1;
		Ldiagonal[n - i + N - 1] = 1;
		func(n + 1);
		straight[i] = 0;
		Rdiagonal[n + i] = 0;
		Ldiagonal[n - i + N - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	func(0);
	cout << ans;
}
