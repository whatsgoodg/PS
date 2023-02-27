#include <iostream>
#include <queue>
using namespace std;

//그리디
//가장 작은 수끼리 묶음을 만들어야 함.
//두 개의 묶음을 만들 때마다 최소힙에 추가하며 비교 
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
