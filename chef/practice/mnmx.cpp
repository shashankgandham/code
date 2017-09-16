#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int t, n, a, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		ans = INT_MAX;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a);
			ans = min(ans, a);
		}
		printf("%lld\n", (ll)ans*(n-1));
	}
	return 0;
}
