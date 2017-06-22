#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, d, flag, c;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &d);
			c += d;
	}	
	if(c/2 != n - 1)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
