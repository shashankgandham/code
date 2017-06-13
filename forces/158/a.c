#include <stdio.h>

int main() {
	int k, n, c, a, i, t;

	scanf("%d %d",&n,&k);
		c = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d",&a);
		if(i < k &&  a > 0) {
			c++;
		}
		else if(i == k) {
			t = a;
			if(a > 0)
				c++;
		}
		else if(a == t && a > 0) {
			c++;
		}

	}
	printf("%d\n",c);
	return 0;
}