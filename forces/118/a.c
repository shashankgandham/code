#include <stdio.h>
#include <string.h>

int main() {
	char s[105], a[205];	
	int j, i;

	scanf("%s",s);

	for(i = 0;i < strlen(s); i++) {
		 if(s[i]>=65&&s[i]<=90)
			        s[i]=s[i]+32;
	}
	i = 0;
	j = 0;
	while(i < strlen(s)) {
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
			i++;
			continue;
		}

		else {
			a[j]='.';
			j++;
			a[j] = s[i];
			i++;
			j++;
		}
	}

	a[j] = '\0';

	printf("%s\n",a);

	return 0;
}