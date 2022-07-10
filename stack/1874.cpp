#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> nums;
	queue <char> orders;
	int n, v; cin >> n;
	int* arr = new int[n];
	int idx = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int count = 0;
	while (count <= n && idx < n) {
		if (nums.empty()) {
			nums.push(++count);
			orders.push('+');
		}
		else if(nums.top() == arr[idx]) {
			nums.pop();
			orders.push('-');
			idx++;
		}
		else {
			nums.push(++count);
			orders.push('+');	
		}
	}

	if (!nums.empty())
		cout << "NO" << "\n";
	else {
		int size = orders.size();
		for (int i = 0; i < size; i++) {
			cout << orders.front() << "\n";
			orders.pop();
		}
	}
}
//스택과 큐를 모두 이용한 풀이
//생각해낸 예외생황: 중간에 스택이 비어있을 때(19번 라인)
//push와 pop을 다 진행하고 스택이 비어있지 않으면 23번 라인의 조건을 한 번이라도 충족하지 못 한것이므로 NO출력
