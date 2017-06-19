#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k, q, c[200005], f[200005], a, b;

int main() {
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		c[a]++;
		c[b+1]--;
	}
	for(int i = 1; i <= 200000; i++) {
		f[i] = f[i-1] + c[i];	
		c[i] = 0;
	}
	for(int i = 1; i <= 200000; i++) {
		if(f[i] >= k)
			c[i]++;
		c[i] += c[i-1];
	}
	for(int i = 0; i < q; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", c[b] - c[a-1]);
	}
	return 0;
}
