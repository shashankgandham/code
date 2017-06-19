#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, a[5001], dp[5001], g[5001], gi, gn[5001];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	dp[n] = gi = 1;
	g[n] = 0;
	for(int i = n - 1; i > 0; i--) {
		for(int j = i + 1; j <= n; j++) {
			if(abs(a[i] - a[j]) == 1 || a[i]%7 == a[j]%7) {
				if(dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					g[i] = g[j];
				}
			}
		}
		if(!dp[i]) {
			dp[i] = 1;
			g[i] = gi++;
		}
	}
//	for(int i = 1; i <= n; i++) 
//		printf("%d %d --> %d %d\n", i, a[i], dp[i], g[i]);
	if(gi == 1)
		printf("%d\n", n);
	
	else {
		for(int i = 1; i <= n; i++) {
			if(!gn[g[i]]) 
				gn[g[i]] = dp[i];
		}
		sort(gn, gn + gi);
		printf("%d\n", gn[gi - 1] + gn[gi - 2]);
	}
	return 0;
}
