#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n, a, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if(!ans && i + a > n)
			ans = i;
	}
	printf("%d\n", ans);
	return 0;
}
