//가벼운 상자부터 하나씩 처리
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, K;
pair<int, int> jewels[300001];
int bags[300001];
multiset<int> prices;
long long ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> jewels[i].first >> jewels[i].second;
	}
	sort(jewels, jewels + N);
	
	for (int i = 0; i < K; i++) {
		cin >> bags[i];
	}
	sort(bags, bags + K);

	int jewel_idx = 0;
	int left_bags = 0;
	prices.insert(0);
	for (int i = 0; i < K && jewel_idx < N; i++) {
		while (jewels[jewel_idx].first <= bags[i]) {
			prices.insert(jewels[jewel_idx].second);
			if (++jewel_idx >= N) break;
		}
		ans += *prices.rbegin();
		if(*prices.rbegin() != 0) prices.erase(--prices.end());
		left_bags = i;
	}

	for (int i = left_bags + 1; i < K; i++) {
		ans += *prices.rbegin();
		if (*prices.rbegin() != 0) prices.erase(--prices.end());
	}
	cout << ans;
}
