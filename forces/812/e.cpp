#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> adj[100005], rb[2];
int depth[100005], a[100005], n, p, mx;	
map<int, int> t;

void dfs(int v, int d = 0) {
	mx = max(mx, d);
	depth[v] = d;
	rb[d%2].push_back(a[v]);

	for(int i = 0; i < adj[v].size(); i++)
		dfs(adj[v][i], d + 1);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 2; i <= n; i++) {
		scanf("%d", &p);
		adj[p].push_back(i);
	}
	dfs(1);
	ll b = 0, ans = 0;
	
	for(int i = 0; i < rb[mx%2].size(); i++)
		b ^= rb[mx%2][i];
	
	for(int i = 0; i < rb[0].size(); i++)
		t[rb[0][i]]++;
	
	if(!b) {
		for(int i = 0; i < rb[1].size(); i++)
			ans += t[rb[1][i]];
		ans += rb[0].size()*(rb[0].size() - 1)/2;
		ans += rb[1].size()*(rb[1].size() - 1)/2;
	}
	else {
		for(int i = 0; i < rb[1].size(); i++)
			ans += t[rb[1][i]^b];
	}
	printf("%lld\n", ans);
	return 0;
}
