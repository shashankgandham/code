#include <bits/stdc++.h>
#define M1 ll(1e9 + 7)
#define M2 ll(1e9 + 9)
typedef long long ll;
using namespace std;

inline ll po(ll x, ll y, ll m) {
	ll res = 1; 
	while (y) {
		res = (y & 1)? (res*x) % m: res;
		y = y>>1, x = (x*x) % m;  
	}
	return res;
}

inline ll solve(ll n, ll MOD) {
	ll p = (po(n, 2, MOD)*(n+1))%MOD;
	ll q = (2*n*(2*n - 1))%MOD;
	return (p*po(q, MOD - 2, MOD))%MOD;
}
int main() {
    ios::sync_with_stdio(false);
	ll t, n;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		printf("%lld %lld\n",solve((n-1)%M1, M1), solve((n-1)%M2, M2));
	}
	return 0;
}
