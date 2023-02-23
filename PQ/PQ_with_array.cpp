#include <iostream>
using namespace std;

int heap[100005];
int sz = 0;

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) { //root까지
		if (heap[idx] >= heap[idx / 2]) break;
		int tmp = heap[idx];
		heap[idx] = heap[idx / 2];
		heap[idx / 2] = tmp;
		idx = idx / 2;
	}
}

int top() { return heap[1]; }

void pop() {
	int root = 1;
	heap[root] = heap[sz--];
	while (2*root <= sz) { //leaf 확인
		int lc = root * 2, rc = root * 2 + 1;
		int min_c = lc;
		if (2*root + 1 <= sz && heap[rc] < heap[min_c]) min_c = rc;
		if (heap[root] <= heap[min_c]) break;
		int tmp = heap[root];
		heap[root] = heap[min_c];
		heap[min_c] = tmp;
		root = min_c;
	}
}

void test() {
	push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
	cout << top() << '\n'; // 2
	pop(); // {10, 5, 9}
	pop(); // {10, 9}
	cout << top() << '\n'; // 9
	push(5); push(15); // {10, 9, 5, 15}
	cout << top() << '\n'; // 5
	pop(); // {10, 9, 15}
	cout << top() << '\n'; // 9
}

int main() {
	test();
}
