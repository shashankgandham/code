#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int d[3000], h[3000], v[3000];
void init() {
	int i;
	for(i = 0; i < 3000; i++) {
		d[i] = 0;
		h[i] = 0;
		v[i] = 0;
	}
}
int main() {
	int n, i, hi, vi, k;

	scanf("%d",&n);
	k = n*n;
	init();
	for(i = 1; i <= k; i++) {
		scanf("%d%d",&hi,&vi);
		if(!(h[hi]) && !(v[vi])) {
			d[i] = 1;
			h[hi] = 1;
			v[vi] = 1;
		}
	}
	for(i = 1; i <=k; i++) {
		if(d[i])
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}