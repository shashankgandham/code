#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
 
int main() {
	ll n, t, a, ans, l, sum, index;
	scanf("%lld", &t);
	vector<ll> negs;
	while(t--) {
		negs.clear();
		scanf("%lld", &n);
		sum = 0, l = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%lld", &a);
			if(a >= 0) {
				sum += a;
				l++;
			}
			else
				negs.push_back(a);
		}
		index = 0;
		sort(negs.rbegin(), negs.rend());
		for(int i = 0; i < negs.size(); i++) {
			if(sum*l <= (sum + negs[i])*(l+1)) {
				sum += negs[i];
				l++;
				index++;
			}
			else break;
		}
		for(int i = index; i < negs.size(); i++)
			ans += negs[i];
 
		ans += sum*l;
		printf("%lld\n", ans);
	}
}
