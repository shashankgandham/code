#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t, n, c[1000005], w[1000005], ans, u[1000005], l;

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		memset(u, 0, sizeof u);
		for(int i = 1; i <= n; i++) 
			scanf("%lld", &c[i]);
		
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &w[i]);
			w[i] += w[i-1];
		}
		ans = 0, l = 1;
		for(int i = 1; i <= n; i++) {
			if(u[c[i]] >= l) {
				ans = max(ans, w[i - 1] - w[l - 1]);
				l = u[c[i]] + 1;
			}
			u[c[i]] = i;
		}
		ans = max(ans, w[n] - w[l - 1]);
		printf("%lld\n", ans); 
	}
	return 0;
}
