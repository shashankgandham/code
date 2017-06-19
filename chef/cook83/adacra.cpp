#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main() {
	int n, ku, kd, l;
	char s[2048];
	scanf("%d", &n);
	while(n--) {
		scanf(" %s", s);
		ku = kd = 0;
		l = strlen(s);
		for(int i = 1; i < l; i++) {
			if(s[i - 1] == 'U' && s[i] == 'D') 
				ku++;
			if(s[i - 1] == 'D' && s[i] == 'U') 
				kd++;
 
		}
		if(s[l - 1] == 'U') 
			ku++;
		if(s[l - 1] == 'D')
			kd++;
		printf("%d\n", min(ku, kd));
	}
	return 0;
}
