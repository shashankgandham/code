#include <bits/stdc++.h>

int main() {
	int n, k;
	char s[500];

	scanf("%d",&n);

	while(n--) {
		scanf("%s",s);

		if(strlen(s) <= 10)
			printf("%s\n",s);
		else
			printf("%c%d%c\n",s[0],strlen(s) - 2,s[strlen(s) - 1]);
	}

	return 0;
}
