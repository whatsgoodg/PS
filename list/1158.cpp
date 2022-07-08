#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, th; cin >> n >> th;
	list<int> L; for (int i = 1; i <= n; i++) L.push_back(i);

	auto move = L.begin();
	cout << '<';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < th - 1; j++) {
			if (move != L.end()) move++;
			else { 
				move = L.begin(); 
				move++;
			}
		}
		if (move == L.end()) move = L.begin();
		if(i != n -1) cout << *move << ", ";
		else cout << *move;
		auto temp = L.erase(move);
		if (temp == L.end()) move = L.begin();
		else move = temp;
	}
	cout << '>';
}
