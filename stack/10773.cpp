#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> money;
	int ans = 0;
	int n; cin >> n;

	int v;
	for (int i = 0; i < n; i++) {
		cin >> v;
		if (v == 0 && !money.empty()) { //0이 들어왔을 때 pop 후 합에서 빼기
			sum -= money.top();
			money.pop();
		}
		else {//들어온 값 push
			money.push(v);
			sum += money.top();
		}
	}
	cout << ans << "\n";
}
