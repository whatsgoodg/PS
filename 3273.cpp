#include <iostream>
using namespace std;

int arr[2000001]{};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int* arr2 = new int[n];

	int v;
	for (int i = 0; i < n; i++) {
		cin >> v;
		arr[v]++;
		arr2[i] = v;
	}
	cin >> v;
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		if (v-arr2[i] > 0 && v-arr2[i] != arr2[i] && arr[v - arr2[i]] == 1) { //1. 입력값의 예외처리, 2. x - v = v의 예외처리
			arr[arr2[i]]--;
			cnt++;
		}
	cout << cnt;
}
