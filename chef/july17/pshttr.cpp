#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define N int(1e5 + 5)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
 
struct query{
	int u, v, k, id;
};

struct info{
	int id, k;
};
 
vector <int> adj[N], co[N];
int n, m, c, t, pos[N], subtree[N], x, y, maxi;
ll T[8*N], ans[N];
info v[N];
query q[100005];
 
bool cmp(query a, query b) {
	return a.k < b.k;
}
bool cmps(info a, info b) {
	return a.k < b.k;
}
 
void dfs(int cur) {
	subtree[cur] = 1;
	for(int i = 0; i < adj[cur].size(); i++) {
		int x = adj[cur][i];
		if(!subtree[x]) {
			v[x].k = co[cur][i];
			v[x].id = x;
			dfs(x);
			subtree[cur] += subtree[x];
		}
	}
	pos[cur] = maxi--;
}
 
void reset() {
	for(int i = 0; i < N; i++) { 
		adj[i].clear();
		co[i].clear();
		ans[i] = pos[i] = subtree[i] =  0;
		q[i].u = q[i].v = q[i].id = 0;
		v[i].k = v[i].id = 0;	
		for(int j = 0; j < 8; j++)
			T[8*i + j] = 0;
	}
}
void lazy_propagation(int node) {
	T[node * 2] ^= T[node]; T[node * 2 + 1] ^= T[node];
	T[node] = 0;
}	
void update(int node, int from, int to, int l, int r, int val) {
	if (from < to) 
		lazy_propagation(node);
 
	if ((from > r) || (to < l)) 
		return;
 
	if ((from >= l) && (to <= r)) {
		T[node] ^= val;
		return;
	}
	int mid = (from + to) / 2;
	update(node * 2, from, mid, l, r, val);
	update(node * 2 + 1, mid + 1, to, l, r, val);
}
int get_val(int node, int from, int to, int pos) {
	if (from < to) 
		lazy_propagation(node);
 
	if (from == to) 
		return T[node];
 
	int mid = (from + to) / 2;
	if(mid >= pos)
		get_val(node * 2, from, mid, pos);
	else
		get_val(node * 2 + 1, mid + 1, to, pos);
}
 
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		reset();
		for(int i = 0; i < n-1; i++) {
			scanf("%d%d%d", &x, &y, &c);
			x--,y--;
			adj[x].pb(y), adj[y].pb(x);
			co[x].pb(c), co[y].pb(c);
		}
		maxi = n;
		dfs(0);
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].k);
			q[i].u--, q[i].v--;
			q[i].id = i;
		}
		sort(q, q+m, cmp);
		sort(v, v+n, cmps);
		int j = 1;
		for(int i = 0; i < m; i++) {
			while(v[j].k <= q[i].k && j <= n) {
				update(1, 1, n, pos[v[j].id], pos[v[j].id] + subtree[v[j].id] - 1, v[j].k);
				j++;
			}
			ans[q[i].id] = get_val(1, 1, n, pos[q[i].u]) ^ get_val(1, 1, n, pos[q[i].v]);
		}
		for(int i = 1; i < 8*n; i++)
			printf("%lld ", T[i]);
		for(int i = 0; i < m; i++)
			printf("%lld\n", ans[i]);
	}
	return 0;
}
 
