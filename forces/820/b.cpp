#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int n, a, ang, mina = 2;
	double cang, obt[100005], act[100005];
	scanf("%d%d", &n, &a);
	cang = 180.00/n;
	for(int i = 2; i < n; i++) {
		if(fabs((i-1)*cang - a) < fabs((mina - 1)*cang - a))
			mina = i;
	}
	printf("%d %d %d\n", 1, mina + 1, mina);
	return 0;
}
