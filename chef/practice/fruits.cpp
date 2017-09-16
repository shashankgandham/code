#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int t, n, m, k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", max(0, max(n, m) - min(n, m) - k)); 
	}
	return 0;
}
