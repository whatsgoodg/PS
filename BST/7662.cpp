#include <iostream>
#include <set>
using namespace std;

int N, K, val;
char in;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	while (N--) {
		cin >> K;
		multiset<int> B;
		while (K--) {
			cin >> in >> val;
			if (in == 'I') {
				B.insert(val);
			}
			else {
				if (B.empty()) continue;
				if (val + 1) B.erase(--B.end());
				else B.erase(B.begin());
			}
		}
		if (B.empty()) cout << "EMPTY\n";
		else cout << *(--B.end()) << ' ' << *B.begin() << '\n';
	}
}
