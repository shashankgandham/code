#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
ll ap(ll a, ll di, ll n) {
	return a + (n * (2*di + (n-1)))/2;
}
 
int main() {
	ll u, v, t;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &u, &v);
		printf("%lld\n", ap(ap(1, 2, u), u + 1, v));
	}
	return 0;
}
