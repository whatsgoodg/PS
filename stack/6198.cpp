#include <iostream>
#include <stack>
using namespace std;

stack<int> S;
int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	int v;
	long ans = 0;
	S.push(0);
	for (int i = 0; i < N; i++) {
		cin >> v;
		while (!S.empty() && S.top() <= v) S.pop();
		ans += S.size();
		S.push(v);
	}
	cout << ans << "\n";
}
