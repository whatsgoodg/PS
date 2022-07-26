#include <iostream>
#include <cmath>
using namespace std;

int N;
void hanoi(int a, int b, int c) {
	if (c == 1) {
		cout << a << " " << b << "\n";
		return;
	}
	hanoi(a, 6 - a - b, c - 1);
	cout << a << " " << b << "\n";
	hanoi(6 - a - b, b, c - 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cout << static_cast<int>(pow(2, N) - 1) << "\n";

	hanoi(1, 3, N);
}
