#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in = "";

	getline(cin, in);
	while (in != ".") {
		stack<char> S;
		bool no = false;
		for (char i : in) {
			if (i == '[' || i == '(') S.push(i);
			else if (i == ']') {
				if (S.empty() || S.top() != '[') {
					no = true;
					break;
				}
				S.pop();
			}
			else if (i == ')') {
				if (S.empty() || S.top() != '(') {
					no = true;
					break;
				}
				S.pop();
			}
		}
		if (!S.empty() || no) cout << "no\n";
		else cout << "yes\n";
		getline(cin, in);
	}
}
