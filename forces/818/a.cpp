#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

ll n, k, c, d;
int main() {
	scanf("%lld%lld", &n, &k);
	d = n/(2*(k + 1));
	c = k*d;
	printf("%lld %lld %lld\n", d, c, n -  c - d);
	return 0;
}
