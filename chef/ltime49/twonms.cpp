#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll n, a, b, t;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld%lld", &a, &b, &n);
		a = (n%2)? 2*a: a;
		printf("%lld\n",max(a,b)/min(a,b));
	}
	return 0;
}
