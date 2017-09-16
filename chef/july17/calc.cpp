#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
 
int main() {
	ll t, n, b, k, c;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &n, &b);
		c = n/(2*b);
		k = max((n - c*b)*c, (n - (c+1)*b)*(c+1));
		printf("%lld\n", k);
	}
	return 0;
}
