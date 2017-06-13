#include <stdio.h>
#include <string.h>

int main() {
	char s[105], p[105];
	int i;
	scanf("%s %s",s,p);
	i = 0;
	while(s[i]) {
		if(s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 'a' +'A';
		i++;
	}
	i = 0;
	while(p[i]) {
		if(p[i] >= 'a' && p[i] <= 'z')
			p[i] = p[i] - 'a' + 'A';
		i++;
	}
	
	i = strcmp(s,p);
	if(i) {
		if(i < 0)
			printf("-1\n");
		else
			printf("1\n");
	}
	else
		printf("%d\n",i);
	return 0;
}