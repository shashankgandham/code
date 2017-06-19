#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int dsum(ll n) {
	int ans = 0;
	while(n) {
		ans += n%10;
		n = n/10;
	}
	return ans;
}
int main() {
	ll n, s, m;
	scanf("%lld%lld", &n, &s);
	m = s; 
	while(m - dsum(m) < s && m <= (n+1)) 
		m++;
	printf("%lld\n", max(0LL, n - m + 1));
	return 0;
}
