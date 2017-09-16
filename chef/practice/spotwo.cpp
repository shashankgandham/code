#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int bit, d[32];

ull convert(int n) {
	ull ans = 0;
	bit = 0;
	while(n > 0) {
		bit++;
		d[bit] = n&1;
		n >>= 1;
	}
	for(int i = bit; i > 0; i--)
		ans = ans*10 + d[i];
	return ans;	
} 
ull power(ull x, ull y) {
    ull res = 1;    
    while (y) {
        if (y & 1)
            res = (res*x) % MOD;
        x = (x*x) % MOD;  
        y = y>>1; 
    }
    return res;
}
int main() {
	int t, n;
	ull ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d",&n);
		ans = power(2LL, convert((ull)n));
		printf("%llu\n", (ans*ans)%MOD);
	}
	return 0;
}
