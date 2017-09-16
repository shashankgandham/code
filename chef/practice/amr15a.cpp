#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, a, c;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		if(a%2)
			c++;
	}
	(c >= (n-c))? printf("NOT READY\n"): printf("READY FOR BATTLE\n");	
	return 0;
}
