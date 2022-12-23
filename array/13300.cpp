#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int men[6]{};
	int women[6]{};

	int n, k; cin >> n >> k;
	int sex, grade;
	for (int i = 0; i < n; i++) {
		cin >> sex >> grade;
		if (sex == 1) men[grade - 1]++;
		else women[grade - 1]++;
	}
	int rooms = 0;
	for (int i = 0; i < 6; i++) {
		rooms += men[i] / k + (men[i] % k != 0 ? 1 : 0) + women[i] / k + (women[i] % k != 0 ? 1 : 0);
	}
	cout << rooms << "\n";
}
