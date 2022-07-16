#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
int ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	cin >> N;
	while (N--) {
		stack<char> S;
		cin >> in;
		for (auto i : in) {
			if (i == 'A') {
				if (!S.empty() && S.top() == 'A') S.pop();
				else S.push(i);
			}
			else {
				if (!S.empty() && S.top() == 'B') S.pop();
				else S.push(i);
			}
		}
		if (S.empty()) ans++;
	}
	cout << ans << "\n";

}
