#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
struct node{
	int c, p, t, m;
};
node a[100005];
vector<int> adj[100005];

void reset() {
	for(int i = 0; i <= 100000; i++) {
		a[i].m = a[i].c = a[i].t = a[i].p = 0;
		adj[i].clear();
	}
	a[1].p = 1;
}

void dfs(int cur) {
	for(int i = 0; i < adj[cur].size(); i++) {
		if(adj[cur][i] != a[cur].p) {
			a[adj[cur][i]].p = cur;
			if(a[cur].c)
				a[adj[cur][i]].t++;
			dfs(adj[cur][i]);
		}
	}
	if(a[cur].m) {
		if(!a[a[cur].p].c && !a[cur].c) {
			a[a[cur].p].c = 1;
			a[cur].t++;
			a[a[cur].p].t += 2;
			a[a[a[cur].p].p].t++;
			a[cur].m = 0;
		}
		else if(a[a[cur].p].c)  
			a[cur].t++, a[cur].m = 0;

		else if(a[cur].c) 
			a[cur].m = 0;
	}
	if(a[cur].t < 2) {
		if(!a[a[cur].p].c && adj[cur].size() != 1 && a[cur].t != 0) {
			a[a[cur].p].c = 1;
			a[cur].t++;
			a[a[cur].p].t += a[cur].t;
			a[a[a[cur].p].p].t++;
		}
		else if(adj[cur].size() == 1 && !a[cur].c) {
			a[cur].c = 1;
			a[cur].t++, a[a[cur].p].t++;
			if(a[cur].t < 2 && !a[a[a[cur].p].p].c)
				a[a[cur].p].m = 1;
		}
		if(a[cur].t == 0) {
			a[cur].c = 1;
			a[cur].t++;
			a[a[cur].p].t++;
		}
	}
}

int main() {
	int t, n, u, v, k;
	scanf("%d", &t);
	while(t--) {
		reset();
		scanf("%d", &n);
		for(int i = 0; i < n - 1; i++) {
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		if(n == 1)
			printf("-1\n");
		else {
			dfs(1);
			k = 0;
			for(int i = 1; i <= n; i++) {
				if(a[i].t < 2) 
					a[i].c = 1;
				if(a[i].c) k++;
			}
			if(!a[1].c && a[1].m) 
				k++;
			printf("%d\n", k);
		}
	}
	return 0;
}
