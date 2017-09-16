#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll t, n, a[50005], sum;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		sum = sum/(n-1);
		for(int i = 1; i <= n; i++)
			printf("%lld ", sum - a[i]);
		printf("\n");
	}		
	return 0;
}
