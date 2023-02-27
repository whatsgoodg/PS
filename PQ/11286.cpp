	#include <iostream>
	#include <queue>
	using namespace std;

	class cmp {
	public:
		bool operator() (int a, int b) { //a 음수 b 음수
			if (a < 0 && b < 0) {
				return a < b;
			}
			else if (a < 0 && b > 0) {  //a 음수 b 양수
				return -1 * a > b;
			}	
			else if (a > 0 && b < 0) {  //a 양수 b 음수
				b = -1 * b;
				return a >= b;
			}
			else {  //a 양수 b 양수
				return a > b;
			}
		}
	};

	priority_queue<int, vector<int>, cmp> PQ;
	int n;
	int val;

	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> n;
		while (n--) {
			cin >> val;
			if (val != 0) {
				PQ.push(val);
			}
			else {
				if (PQ.empty()) cout << 0;
				else {
					cout << PQ.top();
					PQ.pop();
				}
				cout << '\n';

			}
		}
	}
