#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll C(ll n, ll k) {
	if(k == 3)
		return n*(n-1)*(n-2)/6;
	else
		return n*(n-1)/2;
}
ll n, a[100005], ans, e1, e2, e3;
int main() {
	
	scanf("%lld", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	e1 = upper_bound(a, a+n, a[0]) - a;
	if(e1 == 1) {
		e2 = upper_bound(a, a+n, a[1]) - a - 1;
		if(e2 == 1) {
			e3 = upper_bound(a, a+n, a[2]) - a - 2;
			ans = e3;
		}
		else 
			ans = C(e2, 2);
	}
	else if(e1 == 2) {
		e2 = upper_bound(a, a+n, a[2]) - a - 2;
		ans = e2;
	}
	else 
		ans = C(e1, 3);
	
	printf("%lld\n", ans);
	return 0;
}
