#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int t, e, x, y, k;
	scanf("%d", &t);
	while(t--) {
		int city[10005] = {0};
		k = 0;
		scanf("%d", &e);
		while(e--) {
			scanf("%d%d", &x, &y);
			city[x] = 1;
			city[y] = 1;
		}
		for(int i = 1; i <= 10000; i++)
			if(city[i])
				k++;
		printf("%d\n", k);
	}
	return 0;
}
