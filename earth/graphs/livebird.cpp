#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, q, k, s[1000005], l0[1000005], r0[1000005], l1[1000005], r1[1000005];
char c;
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
		scanf("%d",&s[i]);
	for(int i = 1; i < n; i++) {
		if(s[i])
			l1[i + 1] = l1[i] + 1;
		else
			l0[i + 1] = l0[i] + 1;
	}
	for(int i = n - 1; i > 0; i--) {
		if(s[i])
			r0[i] = r0[i + 1] + 1;
		else
			r1[i] = r1[i + 1] + 1;
	}
	scanf("%d", &q);
	n = 0;
	for(int i = 0; i < q; i++) {
		scanf(" %c", &c);
		if(c == 'U')
			n++;
		else {
			scanf("%d", &k);
			if(n%2)
				printf("%d\n", l1[k] + r1[k] + 1);
			else	
				printf("%d\n", l0[k] + r0[k] + 1);
		}
	}
	return 0;
}
