#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> PQ;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N--) {
		int val;
		cin >> val;
		PQ.push(val);
	}

	int cnt = 0;
	while (PQ.size() > 1) {
		int a = PQ.top(); PQ.pop();
		int b = PQ.top(); PQ.pop();
		ans += a + b;
		PQ.push(a + b);
	}
	cout << ans;
}
