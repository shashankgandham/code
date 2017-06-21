#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int M = 2e5 + 10;
typedef long long ll;
ll a[M], fac[M], ncr[M];

ll power(ll n, ll m) {
    ll ret = 1;
    while(m) {
        if(m & 1) ret = ret * n % mod;
        n = n * n % mod;
        m >>= 1;
    }
    return ret;
}
void gen(ll n) {
    fac[0] = 1;
    for(int i = 1 ; i <= n ; i++) 
		fac[i] = (ll)i * fac[i - 1] % mod;
    
	for(int i = 0 ; i <= n ; i++) 
		ncr[i] = fac[n] * power(fac[n - i] * fac[i] % mod , mod - 2) % mod;
}
int main() {
    int n;
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++) 
		scanf("%lld" , &a[i]);
    if(n < 4) {
		if (n == 1)
			printf("%lld\n" , a[0]); 
		else if(n == 2) 
			printf("%lld\n", (a[0] + a[1])%mod);
		else
			printf("%lld\n", (a[0] + 2*a[1] - a[2] + mod)%mod);
		return 0;
	}
    while(n%4) {
        n--;
        int flag = 1;
        for(int i = 0 ; i < n ; i++) {
            if(flag) a[i] += a[i+1];
            else a[i] += mod - a[i+1];
			a[i] %= mod;
            flag ^= 1;
        }
    }
    n = n / 2 - 1;
    ll ans = 0;
	gen(n);
	for(int i = 0 ; i <= n ; i++) {
        ans += ncr[i]*(a[2 * i] - a[2*i + 1] + mod);
        ans %= mod;
    }
	printf("%lld\n", ans);
    return 0;
}
