#include <iostream>
#include <utility>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;
int tail = 1;

void insert(int addr, int num) {
	dat[unused] = num;//1
	pre[unused] = addr;///2
	nxt[unused] = nxt[addr];//3
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;//4 마지막 부분에 원소 삽입시. 예외처리
	else tail = nxt[addr]; //마지막 node
	nxt[addr] = unused;//4
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; //마지막 원소를 지울 때 예외처리
	else tail = pre[addr]; // 마지막 node
}

int main() {
	fill(pre, pre + MX, -1);	
	fill(nxt, nxt + MX, -1);
}
