#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
ll fact(ll a) {
	if( a== 1 || !a)
		return 1;
	return a*fact(a-1);
}
int main() {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", fact(min(a, b)));
	return 0;
}
