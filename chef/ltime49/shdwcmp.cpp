#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int nl[500005], nr[500005], nn = 0, club[500005], cli[500005];
vector<int> ch[500005];
void dfs(int v) {
	nl[v] = n++;
	for(int i = 0; i < ch[v].size(); i++)
		dfs(ch[v][i]);
	nr[v] = n++;
}
int main() {
	int n, q, p, x, ans;
	scanf("%d%d", &n,&q);
	for(int i = 1; i < n; i++) {
		scanf("%d", &p);
		ch[p].push_back(i);
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &club[i]);

	for(int i = 1; i<= q; i++) {

	}
	return 0;
}
