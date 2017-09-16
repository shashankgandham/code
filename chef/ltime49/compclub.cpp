#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;
vector<int> ch[500005], dp[100005];
int club[500005], level[500005], cnt[500005], result[500005];
int t, n, x, p;

int dfs(int v) {
	nl[v] = nx++;
	for(int i = 0; i < ch[v].size(); i++) {
		dfs(ch[v][i]);
	}
	nr[v] = nx++;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &x);
		for(int i = 1; i < n; i++) {
			scanf("%d", &p);
			ch[p].pb(i);
		}
		for(int i = 0; i < n; i++) {
			dp[i].clear(), ch[i].clear();
			seqc[i] = result[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &club[i]);	
			cnt[club[i]]++;
		}
		
		for(int i = 0; i < n; i++) 
			dp[i].resize(cnt[i]);

		for(int i = 0; i < n; i++) 
			scanf("%d", &level[i]);
		
		dfs(0);
		for(int i = 0; i < n; i++)
			printf("%d\n", result[i]);
	}
	return 0;
}
