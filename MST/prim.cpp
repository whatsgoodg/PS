/*
  1. 하나의 정점을 MST에 넣음.
  2. 시작 정점과 연결된 간선 모두 PQ에 저장(min PQ)
  3. PQ에서 가장 가중치가 작은 간선을 꺼냄.
  4. 해당 간선과 이어진 정점이 이미 MST에 포함되어 있는지 확인
  5. 포함되어 있지 않다면 MST에 포함, 포함되어 있으면 버림
  6. 4,5번을 N-1번 반복함.
*/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;


int visited[10001];
vector<pair<int, int>> V[10001];

priority_queue< tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>> > PQ;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, cnt = 0;
	long long ans = 0;
	int first;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, en, len;
		cin >> st >> en >> len;
		V[st].push_back({ len, en });
		V[en].push_back({ len, st });
		first = st;
	}

	visited[first] = 1;
	for (auto iter : V[first]) {
		PQ.push({ iter.first, first, iter.second });
	}
	while (cnt < N - 1) {
		int st, en, cost;
		tie(cost, st, en) = PQ.top(); PQ.pop();
		if (visited[en]) continue;
		visited[en] = 1;
		cnt++;
		for (auto iter : V[en]) {
			if (!visited[iter.second])
				PQ.push({ iter.first, en, iter.second });
		}
		ans += cost;
	}
	cout << ans << '\n';
}
