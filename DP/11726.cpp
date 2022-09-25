#include <iostream>
using namespace std;

int N;
long long DP[1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
    
  DP[1] = 1; DP[2] = 2; //초기값
	for (int i = 3; i <= N; i++) { //점화식
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}
	cout << DP[N];
}
