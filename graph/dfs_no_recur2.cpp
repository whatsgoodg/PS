vector<int> adj[10];
bool vis[10];
void bfs() {
	stack<int> st;
	st.push(1);
	vis[1] = true;
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		cout << cur << ' ';
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			st.push(nxt);
		}
	}
}
