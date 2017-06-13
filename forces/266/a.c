#include <stdio.h>
#include <string.h>

int main() {
	int n, i , k = 0 ,r = 0, g = 0, b = 0;
	char s[100];
	char prev, curr;
	scanf("%d",&n);
	scanf("%s",s);
	i = 1;
	prev = s[0];
	while(s[i]) {
		curr = s[i];
		if(curr == prev)
			k++;
		else
			prev = curr;
		i++;
	}
	printf("%d\n",k);
	return 0;
}