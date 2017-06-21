#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, ans, a[5001], dp[5001][5001], num[100005], maxi[8], p, q;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	
	for(int y = 0; y <= n; y++) {
		for (int i = 1; i <= n; i++)
            num[a[i]] = 0;
        for (int i = 0; i < 8; i++)
            maxi[i] = 0;
		dp[0][y] = dp[y][0];
		for(int x = 1; x <= n; x++) {
			if(y > x)
				dp[x][y] = dp[y][x];
			else if(x == y)
				dp[x][y] = 0;
			else {
				p = max(dp[0][y], maxi[a[x]%7]);
				q = max(num[a[x] - 1], num[a[x] + 1]);
				dp[x][y] = 1 + max(p, q);
			}
			num[a[x]] = max(num[a[x]], dp[x][y]);
			maxi[a[x]%7] = max(maxi[a[x]%7], dp[x][y]);

			ans = max(ans, dp[x][y]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
