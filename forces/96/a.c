#include <stdio.h>
#include <string.h>

int main() {
	int k = 1,i;
	char s[150];

	scanf("%s",s);
	i = 1;
	while(s[i]) {
		if(s[i] == s[i-1])
			k++;
		else
			k = 1;
		if(k == 7) {
			printf("YES\n");
			return 0;
		}
		i++;
	}
	printf("NO\n");
	return 0;
}