#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s, k, t, a[100005], b[100005], ka[100005];
ll solve(ll c) {
	ll sum = 0;
	for(ll i = 0; i < n; i++) {
		b[i] = a[i] + (i+1)*c;
	}
	sort(b, b+n);
	for(ll i = 0; i < c; i++)
		sum += b[i];
	return sum;
}
int main() {
	scanf("%lld%lld", &n, &s);
	for(ll i = 0; i < n; i++) 
		scanf("%lld", &a[i]);
	ll l = 0, r = n + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (solve(m) <= s) l = m;
		else r = m;
	}
	printf("%lld %lld\n", l, solve(l));
	return 0;
}
