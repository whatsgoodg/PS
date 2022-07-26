#include <iostream>
using namespace std;

int N, M;

int arr[9];

bool visited[9];
void func(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		arr[n] = i;
		visited[i] = 1;
		func(n + 1);
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	func(0);
}
