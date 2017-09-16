#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	ll a, b, lim, c;
	scanf("%lld%lld", &a, &b);
	lim = a*a + b;
	c = 0;
	for(ll i = 1; i*i <= lim; i++) {
		c += sqrtl(i*i + b) - i;
	}
	printf("%lld\n", c);
	return 0;
}
