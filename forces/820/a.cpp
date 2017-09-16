#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int c, v0, v1, a, l, n, ans = 0;
	scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);
	n = 0;
	while(n < c) {
		int read = v0 + ans*a;
		if(read > v1)
			read = v1;
		n += read;
		if(ans)	
			n -= l;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
