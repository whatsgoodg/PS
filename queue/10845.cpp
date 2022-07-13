#include <iostream>
using namespace std;

int N;
int arr[10001];
int fst = 0;
int lst = 0;
int Size = 0;

void push(int v) {
	arr[++lst % 10001] = v;
	Size++;
}
int pop() {
	Size--;
	return arr[++fst % 10001];
}

bool empty() { return Size == 0; }

int front() { return arr[(fst + 1) % 10001]; }

int back() { return arr[lst]; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	string in;
	int v;
	for (int i = 0; i < N; i++) {
		cin >> in;
		if (in == "push") {
			cin >> v;
			push(v);
		}
		else if (in == "pop") {
			if (empty()) cout << -1 << "\n";
			else cout << pop() << "\n";
		}
		else if (in == "front") {
			if (empty()) cout << -1 << "\n";
			else cout << front() << "\n";
		}
		else if (in == "back") {
			if (empty()) cout << -1 << "\n";
			else cout << back() << "\n";
		}
		else if (in == "size") {
			cout << Size << "\n";
		}
		else
			cout << empty() << "\n";
	}
}
