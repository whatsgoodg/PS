#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nums[10]{};
	string a; cin >> a;
	int cnt = 1;
	for (int i = 0; i < a.size(); i++) {
		if (nums[a[i] - 48] < cnt) nums[a[i] - 48]++;
		else {
			if (a[i] - 48 == 6 && nums[9] < cnt) nums[9]++;
			else if (a[i] - 48 == 9 && nums[6] < cnt) nums[6]++;
			else {
				cnt++;
				nums[a[i] - 48]++;
			}
		}
	}

	cout << cnt << "\n";
}
