#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll expo(ll x, ll n, ll m){
    ll res = 1;

    while (n){
        if (n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }

    return (res % m);
}

ll extended_gcd(ll a, ll b, ll& x, ll& y){

    if (!b){
        y = 0, x = 1;
        return a;
    }

    ll g = extended_gcd(b, a % b, y, x);
    y -= ((a / b) * x);
    return g;
}

ll inverse_modulo(ll a, ll m){

    ll x, y, inv;
    extended_gcd(a, m, x, y);
    inv = (x + m) % m;
    return inv;
}

ll solve(ll g, ll h, ll p){
    if (h >= p) return -1;
    
	if ((g % p) == 0){
        if (h == 1) 
			return 0;
        else 
			return -1;
    }

    unordered_map <ll, ll> mp;
    ll i, q, r, m = ceil(sqrt(p));
    ll d = 1, inv = expo(inverse_modulo(g, p), m, p);

    for (i = 0; i <= m; i++){
        if (!mp[d]) mp[d] = i + 1;
        d *= g;
        if (d >= p) d %= p;
    }

    d = h;
    for (q = 0; q <= m; q++){
        r = mp[d];
        if (r) return ((m * q) + (--r));
        d *= inv;
        if (d >= p) d %= p;
    }

    return -1;
}
int main() {
	ll t, r, s, p;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld%lld", &r, &s, &p);
		s = (s*(r-1) + 1)%p;
		if(r == 1) 
			printf("%lld\n", s);
		else
			printf("%lld\n", solve(r, s, p));		
	}
	return 0;
}
