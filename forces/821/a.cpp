#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int n, a[64][64], flag;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	flag = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] != 1) {
				flag = 0;
				for(int k = 1; k <= n; k++) {
					for(int l = 1; l <= n; l++) {
						if(a[i][j] == a[i][k] + a[l][j]) {
							flag = 1;
							break;
						}
					}
				}
				if(!flag)
					break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
