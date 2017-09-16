#include <bits/stdc++.h>
#define N int(3e5) + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int n, x, r, ans = 0, flag, a[300005], ind;
int main() {
	char s[16];
	scanf("%d", &n);
	r = flag = 1, ans = ind = 0;
	for(int i = 1; i <= 2*n; i++) {
		scanf(" %s",s);
		if(s[0] == 'a') {
			flag = 1;
			scanf("%d", &x);
			a[ind++] = x;
		}
		else {
			if(flag && ind && a[ind - 1] != r) {
				ans++;
				ind = flag = 0;
			}
			else if(ind) 
				ind--;
			r++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
