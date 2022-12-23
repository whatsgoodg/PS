#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int alpha[26]{};
	int alpha2[26]{};

	string a, b; cin >> a >> b;

	for (int i = 0; i < a.size(); i++) alpha[a[i] - 97]++;
	for (int i = 0; i < b.size(); i++) alpha2[b[i] - 97]++;

	int cnt = 0;
	for (int i = 0; i < b.size(); i++) {
		int differ = alpha[b[i] - 97] - alpha2[b[i] - 97];
		if (differ != 0) {
			cnt += abs(differ);
			alpha[b[i] - 97] = alpha2[b[i] - 97] = 0;
		}
	}
	for (int i = 0; i < a.size(); i++) {
		int differ = alpha[a[i] - 97] - alpha2[a[i] - 97];
		if (differ != 0) {
			cnt += abs(differ);
			alpha[a[i] - 97] = alpha2[a[i] - 97] = 0;
		}
	}
	cout << cnt << "\n";
}
