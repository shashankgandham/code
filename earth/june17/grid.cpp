#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, a[512][512], dp[512][512];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	printf("0\n");
	return 0;
}
