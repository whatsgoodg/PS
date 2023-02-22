//Greedy
//제일 높은 값부터 차례대로
//딱 맞는 가방에 넣는다.

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, K;
pair<int ,int> jewels[300001];
multiset<int> bags;
long long ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> jewels[i].second >> jewels[i].first;
	}
	sort(jewels, jewels + N);

	while (K--) {
		int weight;
		cin >> weight;
		bags.insert(weight);
	}

	for (int i = N - 1; i >= 0; i--) {
		auto bag = bags.lower_bound(jewels[i].second);
		if (bag == bags.end()) {
			continue;
		}
		ans += jewels[i].first;
		bags.erase(bag);
	}
	cout << ans;
}
