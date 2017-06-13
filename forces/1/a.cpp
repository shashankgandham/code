#include<bits/stdc++.h>
typedef long long ll;
int main() {
	ll n, m, a, k, c, d;
	scanf("%lld %lld %lld",&n,&m,&a);
	k = n/a + !(!(n%a));
	c = m/a + !(!(m%a));
	d = k*c;
	printf("%llu", d);
	return 0;
}
