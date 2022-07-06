#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	int val, count = 0; cin >> val;
	for (int i = 0; i < n; i++) if (arr[i] == val) count++;

	cout << count;
	
}
