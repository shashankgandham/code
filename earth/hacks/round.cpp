#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int n, k, x, np, z, a[1024];
	scanf("%d%d%d", &n, &k, &x);
	np = n;
	while(np > x%k) {
		z = x%k;
		np -= z;
		x = (x == n)? 1: x+1;
		while(z) {
			while(a[x])
				x = (x == n)? 1: x+1;
			a[x] = 1, z--;
		}
		while(a[x])
			x = (x == n)? 1: x+1;
	}
	while(a[x])
		x = (x == n)? 1: x+1;
	printf("%d\n", x);
	return 0;
}

