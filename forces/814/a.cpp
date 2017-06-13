#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n, k, a[256], b[256], flag = 0, ans = 0;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(i && flag && !a[i] && a[i-1])
			ans = 1;
		if(!a[i])
			flag = 1;

	}
	for(int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	
	if(k == 1) {
		for(int i = 0; i < n; i++) {
			if(i && a[i] && a[i-1] && a[i-1] > a[i])
				ans = 1;
			else if(i && (!a[i]) && a[i-1] > b[0])
				ans = 1;
			else if(i && (!a[i - 1]) && b[0] > a[i])
				ans = 1;
		}
	}
	else {
		ans = 1;
	}
	if(ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}
