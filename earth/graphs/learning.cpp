#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y) {
	if(x.second == y.second)
		return x.first > y.first;
	else
		return x.second > y.second;
}
int main() {
	int n, m, k, val[1003], x, y;
	vector<pair<int, int>> adj[1003];
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		adj[x].push_back(make_pair(y, val[y]));
		adj[y].push_back(make_pair(x, val[x]));
	}
	for(int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), compare);
	}
	for(int i = 1; i <= n; i++) {
		if(adj[i].size() < k)
			printf("-1\n");
		else
			printf("%d\n",adj[i][k-1].first);
	}
	return 0;
}
