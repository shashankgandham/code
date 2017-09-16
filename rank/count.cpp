#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int n, q, a;
	map<int, vector<int>> x;
	map<int, map<int, int>> ans;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		x[a];
		x[a].pb(i);
	}
	map<int, vector<int>>::iterator it, jt;
	for(it = x.begin(); it != x.end(); it++) 
		sort(((*it).second).begin(), ((*it).second).end());
	for(it = x.begin(); it != x.end(); it++) {
		ans[(*it).first];
		for(jt = x.begin(); it != x.end(); it++) {
			ans[(*it).first][(*jt).first];
			
		}
	}
	return 0;
}
