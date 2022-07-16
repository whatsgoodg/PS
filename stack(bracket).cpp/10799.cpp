#include <iostream>
#include <stack>
using namespace std;

stack<char> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	int ans = 0;

	cin >> in;

	bool laserFlag = false;
	int laserCnt = 0;
	for (auto i : in) {
		if (i == '(') {
			S.push(i);
			laserFlag = true;
		}
		else {
			S.pop();
			if (laserFlag) ans += S.size();
			else ans += 1;
			laserFlag = false;
		}
	}
	cout << ans;
}
