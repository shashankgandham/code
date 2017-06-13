#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *p, const void *q) {
	int a ,b;
	a = *(int *)p;
	b = *(int *)q;

	return a-b;
}

int main() {
	int i, k = 0, a[102];
	char s[102];
	scanf("%s",s);
	for(i = 0; i < strlen(s); i+=2) {
		a[k] = s[i]-'0';
		k++;
	}
	qsort(a,k,sizeof(int),compare);
	for(i = 0; i < k; i++) 
		s[2*i] = a[i] + '0';
	printf("%s\n",s);
	return 0;
}