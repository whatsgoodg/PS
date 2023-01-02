#include <iostream>
#include <utility>
#include <string>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;
int tail = -1;

void insert(int addr, int num) {
	dat[unused] = num;//1
	pre[unused] = addr;///2
	nxt[unused] = nxt[addr];//3
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;//4 마지막 부분에 원소 삽입시. 예외처리
	nxt[addr] = unused;//4
	if(nxt[unused] == -1) tail = nxt[addr]; // 마지막 노드일 시 tail 초기화
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; //마지막 원소를 지울 때 예외처리
	else {
		if (pre[addr] == 0) tail = -1; // empty 될 시에
		else tail = pre[addr]; // 마지막 node
	}
}

int get_addr(int num) {
	int cur = nxt[0];
	while (cur != -1) {
		if (num == dat[cur]) return cur;
	}
	return -1;
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << "\n\n";
}

void print_head_tail() {
	cout << "head: " << (nxt[0] != -1 ? to_string(dat[nxt[0]]) : "it's empty")
		<< ' ' << "tail: " 
		<< (tail == -1 ? "it's empty" : to_string(dat[tail])) << '\n';
}
void insert_test() {
	cout << "****** insert_test *****\n";
	insert(0, 10); // 10(address=1)
	print_head_tail();
	traverse();
	insert(0, 30); // 30(address=2) 10
	print_head_tail();
	traverse();
	insert(2, 40); // 30 40(address=3) 10
	print_head_tail();
	traverse();
	insert(1, 20); // 30 40 10 20(address=4)
	print_head_tail();
	traverse();
	insert(4, 70); // 30 40 10 20 70(address=5)
	print_head_tail();
	traverse();
}
void erase_test() {
	cout << "****** erase_test *****\n";
	erase(1); // 30 40 20 70
	print_head_tail();
	traverse();
	erase(2); // 40 20 70
	print_head_tail();
	traverse();
	erase(4); // 40 70
	print_head_tail();
	traverse();
	erase(5); // 40
	print_head_tail();
	traverse();
	erase(3); // empty
	print_head_tail();
	traverse();
}

int main(void) {
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	insert_test();
	erase_test();
}
