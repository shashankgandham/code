#include <stdio.h>

int main() {
	char s[100];
	int i;
	scanf("%s",s);
	i = 0;

	while(s[i]) {
		if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
			printf("YES\n");
			return 0;
		}
		i++;
	}
	printf("NO\n");
	return 0;
}