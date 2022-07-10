#include <iostream>
using namespace std;

const int capacity = 10000;
int Stack[capacity]{};
int Ssize = 0;
int top = -1;
//스택을 구현해보는 문제
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string in;
	int v;
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in == "push") {
			cin >> v;
			Stack[++top] = v;
			Ssize++;
		}
		else if (in == "top") {
			if (Ssize == 0) cout << -1 << "\n";
			else cout << Stack[top] << "\n";
		}
		else if (in == "size") cout << Ssize << "\n";
		else if (in == "pop") {
			if (Ssize==0) cout << -1 << "\n";
			else {
				cout << Stack[top--] << "\n";
				Ssize--;
			}
		}
		else cout << (Ssize==0) << "\n";

	}
}
