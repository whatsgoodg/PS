#include <iostream>
#include <deque>
using namespace std;

int N1, N2;
deque<int> D;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N1 >> N2;
	for (int i = 1; i <= N1; i++) D.push_back(i);

	int ans = 0;
	int v;

	for (int i = 0; i < N2; i++) {
		int idx = 0;
		cin >> v;
		for (auto iter = D.begin(); iter != D.end(); iter++) { //int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin();로 대체 가능
			if (*iter == v) break;
			idx++;
		}
		while (D.front() != v) {
			if ((D.size() / 2 + D.size() % 2) - 1 >= idx) { //idx < DQ.size() - idx로 대체 가능
				int temp = D.front();
				D.pop_front();
				D.push_back(temp);
				ans++;
			}
			else {
				int temp = D.back();
				D.pop_back();
				D.push_front(temp);
				ans++;
			}
		}
		D.pop_front();

	}
	cout << ans << "\n";

}
