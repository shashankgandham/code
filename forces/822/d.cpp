#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int t, l, r, f[5000005], lprime[5000005], ans, p;

void sieve() {
	lprime[1] = 1;
	for(int i = 2; i <= r; i++) {
		if(!lprime[i]) {
			for(int j = 2*i; j <= r; j += i) {
				if(!lprime[j]) 
					lprime[j] = i;
			}
			f[i] = ((ll)i*(i-1)/2)%MOD;
		}
	}
	f[1] = 0;
}

void calc(ll x) {
	if(f[x] || x == 1)
		return;
	calc(x/lprime[x]);
	f[x] = ((x/lprime[x])*f[lprime[x]] + f[x/lprime[x]])%MOD;
} 
int main() {
	scanf("%d%d%d", &t, &l, &r);
	sieve();
	for(int i = r; i >= l; i--) 
		 calc(i);
	p = 1;
	for(int i = l; i <= r; i++) {
		if(i - l) 
			p = ((ll)p * t)%MOD;
		ans = (ans + (ll)p*f[i])%MOD;
	}
	printf("%d\n", ans);
	return 0;
}
