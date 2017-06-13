#include <stdio.h>

int main() {

	int n, a, b, c, k;

	scanf("%d",&n);
	k = 0;
	while(n--) {
		scanf("%d %d %d",&a,&b,&c);

		if(a&&b || b&&c || c&&a)
			k++;
	}
	printf("%d\n",k);

	return 0;
}