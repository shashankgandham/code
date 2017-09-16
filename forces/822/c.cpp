#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int visited[200005];
int main() {
	int n, x, l, r, c, ans = INT_MAX;
	map<int, map<int, int> >b;
	scanf("%d%d", &n, &x);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &l, &r, &c);
		b[r - l + 1];
		b[r - l + 1][l];
		if(b[r - l + 1][l] != 0)
			b[r-l+1][l] = min(b[r-l+1][l], c);
		else
			b[r-l+1][l] = c;
	}
	map<int, map<int, ll> >:: iterator it, jt;
	for(it = b.begin(); it != b.end(); it++) {
		if(visited[it->first])
			break;
		visited[x - it->first] = visited[it->first] = 1;
		jt  = b.find(x - it->first);
		if(jt != b.end()) {
			map<int, ll>:: iterator xt, yt;
			xt = b[it->first].begin();
			while(xt != b[it->first].end()) {
//				printf("%d %d %lld\n", it->first, xt->first, xt->second);
				yt = b[jt->first].upper_bound(it->first + xt->first - 1);
				while(yt != b[jt->first].end()) {
					ans = min(ans, yt->second + xt->second);
					yt++;
				}
				xt++;
			}
		}
	}	
	if(ans == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
