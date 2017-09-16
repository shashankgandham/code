#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
ll m, b, x, y, ans, res;

int main() {
	scanf("%lld%lld", &m, &b);
	while(1) {
		x = m*b - m*y;
		if(x < 0)
			break;
		res = (x+1)*(y+1)*(x+y)/2;
		ans = max(ans, res);
		y++;
	}
	printf("%lld\n", ans);
	return 0;
}
