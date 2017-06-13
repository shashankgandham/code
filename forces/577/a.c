#include <stdio.h>

int main() {
	int n, x, i, k = 0;

	scanf("%d %d",&n,&x);

	for(i = 1; i <= n; i++) {
		if(!(x%i) && x/i <= n) {
			k++;
		}
	}
	printf("%d\n",k);

	return 0;
}