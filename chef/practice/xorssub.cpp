#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int t, k, n, a[1024], ans, dp[1024][1024];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		dp[0][0] = 1;
		
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 1024; j++)
				dp[i][j] = dp[i - 1][j] | dp[i - 1][j^a[i]];
		ans = 0;
		for(int i = 0; i < 1024; i++) 
			ans = max(ans, dp[n][i] * (i^k));
		printf("%d\n", ans);
	}	
	return 0;
}
