#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int a[128], n, m, l[128], b[128], k;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) 
		scanf("%d", &l[i]);
	if(n == 1 && l[1] == 1) {
		printf("%d\n", 1);
		return 0;
	}
	for(int i = 1; i < m; i++) {
		k = l[i + 1] - l[i];
		if(k <= 0) k += n;
		a[l[i]] = k;
		b[k]++;
	}
	
	for(int i = 1; i <= n; i++) {
		if(b[i] != 1) {
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
