#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int facts[100005], dp[100005][8];

void sieve() {
	for(int i = 2; i <= 100000; i++) {
		if(!facts[i]) {
			for(int j = 1; (i*j) <= 100000; j++) 
				facts[i*j]++;
		}
	}
	for(int i = 2; i <= 100000; i++) {
		for(int j = 1; j < 8; j++)
			dp[i][j] = dp[i-1][j];
		
		dp[i][facts[i]]++;
	}
}
int main() {
	sieve();
	int t, a, b, k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &a, &b, &k);
		printf("%d\n", dp[b][k] - dp[a-1][k]);
	}
	return 0;
}
