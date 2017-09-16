#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	ll t, n, d, a[100005], sum, l, avg, flag, ans;
	scanf("%lld", &t);
	while(t--) {
		ans = 0, flag = 0, sum = 0;
		scanf("%lld%lld", &n, &d);
		for(int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		flag = (sum%n)? 1: 0;
		if(!flag) {
			avg = sum/n;
			for(int i = 0; i < d; i++) {
				sum = 0, l = 0;
				for(int j = i; j < n; j += d) {
					sum += a[j];
					l++;
					ans += abs(avg - a[j]);
				}
				if(sum/l != avg || sum%l)
					flag = 1;
			}
		}
		if(!flag)
			printf("%lld\n", ans/2);
		else
			printf("-1\n");
	}
	return 0;
}
