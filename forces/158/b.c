#include <stdio.h>

int main() {

	int n, s[5] = {0}, k, c;

	scanf("%d",&n);
	k = 0;
	while(n--) {
		scanf("%d",&c);
		s[c]++;
	}

	k+=s[4];
	if(s[3] >= s[1]) {
		s[1] = 0;
		k+= s[3];
	}
	else if(s[3] < s[1]) {
		s[1]-=s[3];
		k+=s[3];
	}

	if(s[2]) {
		k+= s[2]/2;
		s[2] = s[2]%2;
	}
	
	if(s[1]) {
		k+= s[1]/4;
		s[1] = s[1]%4;
	}
	
	if(s[2] || s[1]) {
		if(s[2]) {
			k++;
			s[1]-=2;
		}
		if(s[1] > 0)
			k++;
	}

	printf("%d\n",k);
	return 0;
}