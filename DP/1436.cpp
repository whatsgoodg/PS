#include <iostream>
#include <utility>
using namespace std;

//점화식: min(DP[i - 1],  DP[i / 2],  DP[i / 3] )

int D[1000001];
int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
	}
	cout << D[N];
}
