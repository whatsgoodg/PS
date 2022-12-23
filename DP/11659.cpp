#include <iostream>
using namespace std;

int arr[100001][2];
int N, M;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0];
		arr[i][1] = arr[i][0] + arr[i - 1][1];
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		int I = i, J = j;
		cout << arr[j][1] - arr[i - 1][1] << '\n';
	}
}
