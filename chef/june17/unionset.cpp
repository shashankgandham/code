#include <bits/stdc++.h>
using namespace std;
int t, n, k, len[4096], x, ans, val[4096][4096], flag;
int main() {
	scanf("%d", &t);
	while(t--) {
		memset(val, 0, sizeof val);
		ans = 0;
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; i++) {
			scanf("%d", &len[i]);
			for(int j = 0; j < len[i]; j++) {
				scanf("%d", &x);
				val[i][x] = 1;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				flag = 1;
				for(int l = 1; l <= k; l++) {
					if(!val[i][l] && !val[j][l]) {
						flag = 0;
						break;
					}
				}
				if(flag) ans++;
			}		
		}
		printf("%d\n", ans);
	}
	return 0;
}
