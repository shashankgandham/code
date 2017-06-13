#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	int k = 0, n = 0, i = 1;

	scanf("%s",s);
	
	if(s[0] >= 'a' && s[0] <='z') {
		k = 1 , n = 1;
		while(s[i]) {
			if(s[i] >= 'A' && s[i] <= 'Z') 
				k++;
			n++;
			i++;
		}
	}
	if(n == k && n && k) {
		i = 1;
		s[0] = s[0] - ('a' - 'A');
		while(s[i]) {
			s[i] = s[i] + ('a' - 'A');
			i++;
		}

		printf("%s\n",s);
		return 0;
	}

	else {
		if(k != n) {
			printf("%s\n",s);
			return 0;
		}
		else if ( !n && !k) {
			if(s[0] >= 'A' && s[0] <= 'Z') {
				k = 1;
				n = 1;
				while(s[i]){
					 if(s[i] >= 'A' && s[i] <= 'Z')
						k++;
		                         n++;
					 i++;
				}
				
				if(n == k) {
					i = 0;
					while(s[i]) {
						s[i] = s[i] + ('a' - 'A');
						i++;
					}
					printf("%s\n",s);
					return 0;
				}
			}
		}
		printf("%s\n",s);
		return 0;
	}
}