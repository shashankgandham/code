#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int visited[200005], n, x, par[200005], depth[200005], level[200005];
vector<int> tree[200005];

void dfs(int v, int l) {
	visited[v] = 1;
	level[v] = l;
	for(int i = 0; i < tree[v].size(); i++) {
		if(!visited[tree[v][i]]) {	
			par[tree[v][i]] = v;
			dfs(tree[v][i], l + 1);
		}
	}
	depth[v]++;
	depth[par[v]] = max(depth[par[v]],depth[v]);
}
int main() {
	int u, v;
	scanf("%d%d", &n, &x);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1, 1);
    u = x;
	while(level[x]-level[par[u]] < level[par[u]] - 1)
        u = par[u];

	printf("%d\n", 2*level[u] + 2*depth[u] - 4);
	return 0;
}
