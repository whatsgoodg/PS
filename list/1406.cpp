#include <iostream>
using namespace std;

//0번째부터 마지막 원소가 있는 곳 까지를 커서의 위치로 본다.
//예를 들어 커서는 0 번째 원소가 있는 곳의 index이다.
//단어 사이에 있을 경우 커서는 왼쪽 단어가 기준이 된다. 그렇기 때문에 커서는 왼쪽 단어가 있는 index이다.
char elem[600002]{};
int pre[600002]{};
int nxt[600002]{};
int unused = 1;
int cursor;
void print();
void insert(char e, int addr) { //Insert function 
	elem[unused] = e;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1)  pre[nxt[addr]] = unused; //맨 마지막에 원소 삽입시 #1
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) { //erase 함수
	cursor = pre[addr];
	if (nxt[addr] != -1)  pre[nxt[addr]] = pre[addr]; //맨 마지막 원소 삭제시 #2
	nxt[pre[addr]] = nxt[addr];
}

void print() {
	int header = nxt[0];
	while (header != -1) {
		cout << elem[header];
		header = nxt[header];
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	elem[0] = -1;
	pre[0] = -1;
	nxt[0] = -1;

	string in; cin >> in;
	for (char i : in) insert(i, unused - 1);
	cursor = unused;
	int n; cin >> n; 
	char in2;
	for (int i = 0; i < n; i++) {
		cin >> in2;
		if (in2 == 'L') {
			if (pre[cursor] != -1) //맨 왼쪽일 경우 커서 움직임x
				cursor = pre[cursor];
		}
		else if (in2 == 'D') {
			if (nxt[cursor] != -1)//맨 오른쪽일 경우 커서 움직임x
				cursor = nxt[cursor];
		}	
		else if (in2 == 'B') {//맨 왼쪽일 경우
			if (cursor != 0)
				erase(cursor);
		}
		else if(in2 == 'P') {
			char in3;
			cin >> in2;
			insert(in2, cursor);
			cursor = nxt[cursor];
		}
	}
	print();
}
