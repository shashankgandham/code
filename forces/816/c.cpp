#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, a[128][128], r[128], c[128], b[128][128], flag, k;
void row_first() {
	r[1] = INT_MAX;
	for(int i = 1; i <= m; i++) 
		r[1] = min(r[1], a[1][i]);
		
	if(r[1])
		k += r[1];	
	
	for(int i = 1; i <= m; i++) { 
		c[i] = a[1][i] - r[1];
		if(c[i])
			k+= c[i];
	}
	
	for(int i = 2; i <= n; i++)  {
		r[i] = a[i][1] - c[1];
		if(r[i])
			k+= r[i];
	}

}
void col_first() {
	c[1] = INT_MAX;
	for(int i = 1; i <= n; i++) 
		c[1] = min(c[1], a[i][1]);
		
	if(c[1])
		k += c[1];	
	
	for(int i = 1; i <= n; i++) { 
		r[i] = a[i][1] - c[1];
		if(r[i])
			k+= r[i];
	}
	
	for(int i = 2; i <= m; i++)  {
		c[i] = a[1][i] - r[1];
		if(c[i])
			k+= c[i];
	}
}
int main() {
	flag = 0;
	scanf("%d%d\n", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	(n > m)? col_first(): row_first();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(r[i] < 0 || c[j] < 0 || r[i] + c[j] != a[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", k);
	for(int i = 1; i <= n; i++) {
		while(r[i]--)
			printf("row %d\n", i);
	}
	for(int i = 1; i <= m; i++) {
		while(c[i]--)
			printf("col %d\n", i);
	}
	return 0;
}
