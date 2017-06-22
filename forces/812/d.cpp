#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, k, q, c, t, co, flag;
int in[100005], out[100005], sz[100005], tt = 1, root[100005], ind[100005];
vector<int> g[100005];

void dfs(int v) {
	in[v] = tt++;
	sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++) {
		dfs(g[v][i]);
		sz[v] += sz[g[v][i]];
	}
	out[v] = tt++;

}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 0; i < k; i++) {
		scanf("%d%d", &c, &t);
		if(ind[t]) {
			g[ind[t]].push_back(c);
			root[c] = 1;
		}
		ind[t] = c;
	}
	for(int i = 1; i <= n; i++)
		if(!root[i])
			dfs(i);

	for(int i = 0; i < q; i++) {
		scanf("%d%d", &c, &t);
		if(!ind[t])	
			printf("%d\n", 0);
		else if(in[c] <= in[ind[t]] && out[c] >= out[ind[t]])
			printf("%d\n", sz[c]);
		else
			printf("%d\n", 0);
	}
	return 0;
}
