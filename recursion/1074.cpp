#include <iostream>
#include <cmath>
using namespace std;

int N, R, C;
int Z(int N, int r, int c) {

	if (N == 0) return 0;
	
	int half = pow(2, N - 1);
	if (r < half && c < half) return Z(N - 1, r, c);
	else if (r < half && c >= half) return half * half + Z(N - 1, r, c - half);
	else if(r >= half && c < half) return 2 * half * half + Z(N - 1, r - half, c);
	else if(r >= half && c >= half) return 3 * half * half + Z(N - 1, r - half, c - half);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> R >> C;

	cout << Z(N, R, C);
}
