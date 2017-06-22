#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, x;
ll ans;
int a[2048][2048];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			x = 0;
			for(int k = 1; k <= n; k++)
				x += (a[i][k] && a[j][k])? 1: 0;
			
			ans += (ll)x*(x-1);
		}
	}
	printf("%lld\n", ans/4);
	return 0;
}
