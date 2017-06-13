#include <stdio.h>

int main() {
	char s[10];
	int x = 0, n;

	scanf("%d",&n);

	while(n--) {
		scanf("%s",s);

		if(s[1] == '-')
			x--;
		else
			x++;
	}
	printf("%d\n",x);
	return 0;
}