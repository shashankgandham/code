#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int i,t,n,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		if(k == 1) 
			printf("1\n");

		else if(2*k<=n) {
			for(i = 1; i <= k; i++) 
				printf("%d ",i*2);
			printf("\n");

		}
		else
			printf("-1\n");
	}
	return 0;
}
