#include <iostream>
#include <cassert>
using namespace std;

const int M = 1000003; //table의 크기
const int a = 1000; // 가중치

const int MX = 500005; // 최대 삽입 횟수
//load factor = 500005 / 1000003 = 0.5

// 해시 테이블
int head[M]; // 리스트의 시작 원소 InsertFront의 방식 새 노드가 head에 계속 삽입됨.
// list를 다룰 배열
int pre[MX]; 
int nxt[MX];
string key[MX]; 
int val[MX];
int unused = 0;

int my_hash(string& s) {
    int h = 0;
    for (auto x : s)
        h = (h * a + x) % M;
    return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// key에 대응되는 value를 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k) {
    int Hash = my_hash(k);
    int probe = head[Hash];
    while (probe != -1) {
        if (key[probe] == k) return probe;
        probe = nxt[probe];
    }
    return -1;
}

void insert(string k, int v) {
    int new_idx = find(k);
    if (new_idx != -1) { // key가 이미 존재할 때
        val[new_idx] = v;
        return;
    }
    int Hash = my_hash(k);
    key[unused] = k;
    val[unused] = v;
    if (head[Hash] != -1) { // 충돌이 일어났을 때 리스트 연결 
        pre[head[Hash]] = unused;
        nxt[unused] = head[Hash];
    }
    head[Hash] = unused;
    unused++; 
}

void erase(string k) {
    int del_idx = find(k);
    if (del_idx == -1) return; // 존재하지 않을 때,
    if (pre[del_idx] != -1) nxt[pre[del_idx]] = nxt[del_idx]; //이전 노드 -> 다음 노드
    if (nxt[del_idx] != -1) pre[nxt[del_idx]] = pre[del_idx]; //이전 노드 <- 다음 노드
    int Hash = my_hash(k); 
    if (Hash == del_idx) head[Hash] = nxt[del_idx]; // 삭제노드가 head일 경우
}
void test() {
    insert("orange", 724); // ("orange", 724)
    insert("melon", 20); // ("orange", 724), ("melon", 20)
    assert(val[find("melon")] == 20);
    insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
    insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
    insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
    assert(val[find("banana")] == 52);
    assert(val[find("orange")] == 100);
    erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
    erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
    assert(find("orange") == -1);
    erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
    insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
    assert(val[find("orange")] == 15);
    insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
    insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
    insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
    assert(val[find("cherry")] == 27);
    erase("xxxxxxx");
    assert(find("xxxxxxx") == -1);
    assert(val[find("apple")] == 36);
    assert(val[find("melon")] == 20);
    assert(val[find("banana")] == 52);
    assert(val[find("cherry")] == 27);
    assert(val[find("orange")] == 701);
    assert(val[find("lemon")] == 6);
    cout << "good!\n";
}

int main() {
    fill(head, head + M, -1);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    test();
}
