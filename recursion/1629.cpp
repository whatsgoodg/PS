#include <iostream>
using namespace std;

#define LL long long
LL A, B, C;

LL POW(int a, int b, int m) {
	if (b == 1) return a % m;
	LL val = POW(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0) return val;
	return val * a % m;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C;

	cout << POW(A, B, C);
}
