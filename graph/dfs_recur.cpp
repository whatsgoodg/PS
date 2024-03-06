vector<int> adj[10];
bool vis[10];
void dfs(int cur) {
	vis[cur] = true;
	cout << cur << '\n';
	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs(nxt);
	}
}
