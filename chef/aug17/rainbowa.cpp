#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int t, n, a[1024], flag, x, b[1024];
	scanf("%d", &t);
	while(t--) {
		flag = 1;
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for(int i = 0; i < n; i++) {
			scanf("%d", &x);
			if(x == 6 && a[7])
				flag = -1;
			a[x] += flag;
			b[x] = 1;
		}
		flag = 1;
		for(int i = 1; i < 7; i++) {
			if(!b[i] || a[i]) {
				flag = 0;
	//			printf("%d %d %d\n",i, b[i], a[i]);
			}
		}
		if(!b[7] || b[8] || b[9] || b[10])
			flag = 0;
		(flag)? printf("yes\n"): printf("no\n");
	}
	return 0;
}
