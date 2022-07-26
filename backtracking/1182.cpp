#include <iostream>
using namespace std;

int N, S;
int sequence[30];
int ans = 0;

void subsequence(int n, int sum) {
	if (n == N) {
		if (sum == S) ans++;
		return;
	}
	subsequence(n + 1, sum);
	subsequence(n + 1, sum + sequence[n]);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> sequence[i];
	subsequence(0, 0);
	if (S == 0) ans--;
	cout << ans;
}
