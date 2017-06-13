#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, l, r, sum = 0, ans = -1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		sum += a;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &l, &r);
		if(ans == -1 && (l <= sum && r>= sum || l >= sum)) 
			ans = max(l, sum);
	}
	printf("%d\n", ans);
	return 0;
}
