#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	ll t, n, a, ans;
	scanf("%lld", &t);
	while(t--) {
		ans = 0;
		scanf("%lld", &n);
		for(int i = 0; i < n; i++) {
			scanf("%lld", &a);
			ans = ans | a;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
