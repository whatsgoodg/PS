#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> S;
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int v; cin >> v;
	S.push({v, 0});
	int* arr = new int[N];
	for (int i = 1; i < N; i++) {
		cin >> v;
		while (!S.empty() && S.top().first < v) { //top보다 더 큰 원소가 한 번 나타난다면 오른쪽에서 top의 원소보다 큰 원소 중 가장 왼쪽에 있다는 조건을 만족
			arr[S.top().second] = v;
			S.pop();
		}
		S.push({v, i});
	}
	while (!S.empty()) {
		arr[S.top().second] = -1;
		S.pop();
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
