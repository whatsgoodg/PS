int edge[10][2];
int deg[10]; // 각 정점의 degree
int* adj[10];
int idx[10]; // 현재 정점의 위치
int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> edge[i][0] >> edge[i][1];
		deg[edge[i][0]]++; deg[edge[i][1]]++;
	}
	for (int i = 1; i <= v; i++) {
		adj[i] = new int[deg[i]];
	}
	for (int i = 0; i < e; i++) {
		int u = edge[i][0], v = edge[i][1];
		adj[u][idx[u]] = v;
		idx[u]++;
		adj[v][idx[v]] = u;
		idx[v]++;
	}
}
