#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int n, a[1005], k, c, i, d, z;
	scanf("%d",&n);

	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	k = 0;
	i = 0;
	c = 0;
	d = 0;
	z = n;
	while(z) {
		if(k >= a[i] && a[i] != -1){
			k++;
			a[i] = -1;
			z--;
		}
		if(i == (n-1) && d!= 1 && z) {
			d = 1;
			c++;
		}
		if(i == 0 && d!= 0 && z) {
			d = 0;
			c++;
		}
		if(d)
			i--;
		else
			i++;
	}
	printf("%d\n",c);
	return 0;
}