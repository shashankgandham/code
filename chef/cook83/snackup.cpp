#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int t, n, a[128][2];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			a[i][0] = i;
			a[i][1] = i + 1;
			if(a[i][1] > n)
				a[i][1] = 1;
		}
		printf("%d\n", n);
		for(int j = 0; j < n; j++) {
			printf("%d\n", n);
			for(int k = 1; k <= n; k++) {
				int ind = k + j;
				if(k + j > n)
					ind %= n;
				printf("%d %d %d\n", k, a[ind][0], a[ind][1]);
			}
		}
	}
	return 0;
}
