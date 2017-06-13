#include <stdio.h>

int main() {
	int n, a, b, max = 0, sum = 0;

	scanf("%d",&n);

	while(n--) {
		scanf("%d %d",&a,&b);
		sum += (b - a);
		if(sum > max)
			max = sum;
	}
	printf("%d\n",max);

	return 0;
}