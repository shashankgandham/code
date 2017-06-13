#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int t, n, i, a[100005], p[100005],c[100005],cost = 0, min = 0, x;
	scanf("%d",&n);
	p[0] = INT_MAX;
	for(i = 1; i <= n; i++) {
		scanf("%d%d",&a[i] , &p[i]);
		if(p[i] < p[min])
			min = i;
	}
	c[n+1] = 0;
	c[0]= 0;
	for(i = n; i > 0; i--) {
		a[i] += a[i + 1];
	}
	cost = a[min] * p[min];
	while(min) {
		x = min;
		min = 0;
		for(i = 1; i < x; i++) {
			if(p[i] < p[min])
				min = i;
		}
		if(min)
			cost += ((a[min] - a[x])*p[min]);
	}
	printf("%d\n",cost);			
	
	return 0;
}