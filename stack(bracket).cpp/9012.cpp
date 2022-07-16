#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	cin >> N;
	while (N--) {
		stack<char> S;
		bool NO = false;
		cin >> in;

		for (auto i : in) {
			if (i == '(')
				S.push(i);
			else {
				if (S.empty() || S.top() != '(') {
					NO = true;
					break;
				}
				S.pop();
			}
		}
		if (!S.empty() || NO) cout << "NO\n";
		else cout << "YES\n";
	}

}
