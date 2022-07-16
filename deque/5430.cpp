#include<iostream>
#include <string>
#include <deque>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	string in, arr;
	int n, v;
	while (N--) {
		deque<int> D;
		int r = 0;
		bool errorFlag = false;

		cin >> in >> n >> arr;

		string num = "";
		for (int i = 0; i < arr.size(); i++) {
			if (isdigit(arr[i])) num += arr[i];
			else {
				if (!num.empty()) {
					D.push_back(stoi(num));
					num = "";
				}
			}
		}
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == 'D') {
				if (D.empty()) {
					errorFlag = true;
					break;
				}
				if (r % 2 == 1) D.pop_back();
				else D.pop_front();

			}
			else r++;
		}
		if (errorFlag) cout << "error" << "\n";

		else {
			if (D.empty()) cout << "[]\n";

			else if (r % 2 == 1) {
				cout << "[";
				int size = D.size() - 1;
				while (size--) {
					cout << D.back() << ",";
					D.pop_back();
				}
				cout << D.front() << "]\n";
			}
			else {
				cout << "[";
				int size = D.size() - 1;
				while (size--) {
					cout << D.front() << ",";
					D.pop_front();
				}
				cout << D.back() << "]\n";
			}
		}
	}
}
