#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int dp[4][64];

void sieve() {
	for(int i = 1; i <= 50; i++)
		dp[1][i] = n;
		
	dp[2][1] = 2, dp[2][2] = 4;
	dp[2][3] = 4;
	for(int i = 4; i <= 50; i++)
		dp[2][i] = i;
	
	dp[3][1] = 3, dp[3][2] = 4;
	dp[3][3] = 4;
	for(int i = 4; i <= 50; i++)
		dp[3][i] = i;
}
int main() {
	int t, n, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
