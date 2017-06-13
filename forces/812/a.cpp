#include <bits/stdc++.h>

int main() {
	int l[8], s[8], r[8], p[8];
	for(int i = 1; i <= 4; i++)
		scanf("%d%d%d%d", &l[i], &s[i], &r[i], &p[i]);

	if((l[1] || l[4] || s[4] || r[4] || r[3] || s[2]) && p[4])
		printf("YES\n");
	else if((l[4] || l[3] || s[3] || r[3] || r[2] || s[1]) && p[3])
		printf("YES\n");
	else if((l[3] || l[2] || s[2] || r[2] || r[1] || s[4]) && p[2])
		printf("YES\n");
	else if((l[2] || l[1] || s[1] || r[1] || r[4] || s[3]) && p[1])
		printf("YES\n");
	else printf("NO\n");

	return 0;


}
