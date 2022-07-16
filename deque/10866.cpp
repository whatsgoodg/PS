#include <iostream>
using namespace std;

int N;
int D[20001];
int fst = 20001 / 2 + 1;
int lst = 20001 / 2 + 1;
int Size = 0;

void push_front(int v) {
	D[fst--] = v;
	Size++;
}
void push_back(int v) {
	D[++lst] = v;
	Size++;
}
int pop_front() { 
	Size--;
	return D[++fst];
}
int pop_back() { 
	Size--;
	return D[lst--]; 
}

bool empty() { return Size == 0; }

int front() {
	return D[fst + 1];
}
int back() {
	return D[lst];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	string in;
	int v;
	for (int i = 0; i < N; i++) {
		cin >> in;
		if (in == "push_back") {
			cin >> v;
			push_back(v);

		}
		else if (in == "push_front") {
			cin >> v;
			push_front(v);
		}
		else if (in == "pop_back") {
			if (empty()) cout << -1 << "\n";
			else cout << pop_back() << "\n";
		}
		else if (in == "pop_front") {
			if (empty()) cout << -1 << "\n";
			else cout << pop_front() << "\n";
		}
		else if (in == "back") {
			if (empty()) cout << -1 << "\n";
			else cout << back() << "\n";
		}
		else if (in == "front") {
			if (empty()) cout << -1 << "\n";
			else cout << front() << "\n";
		}
		else if (in == "size") cout << Size << "\n";
		else cout << empty() << "\n";
	}
}
