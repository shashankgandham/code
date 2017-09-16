#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll n, m, a, b;
	scanf("%lld%lld", &n, &m);
	a = sqrt(n);
	b = (sqrt(1 + 4*m) - 1)/2;
	(a > b)? printf("Valera\n"): printf("Vladik\n");
	return 0;
}
