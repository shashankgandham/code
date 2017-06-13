#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll X[64],Y[64], R[4096];

int main(){
	ll x, y, l, r, n = 0, res = 0, prev;
	scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
	X[0] = Y[0] = 1;
	for(int i = 1; (r+10)/X[i-1] >= x; i++)
		X[i] = X[i-1]*x;

	for(int i = 1; (r+10)/Y[i-1] >= y ;i++)
		Y[i] = Y[i-1]*y;

	for(int x = 0; X[x] != 0; x++)
		for(int y = 0; Y[y] != 0; y++) 
			R[n++] = X[x] + Y[y];

	sort(R, R + n);
	prev = l - 1;
	for(int i = 0; i < n; i++){
		if(R[i] > r)
			break;
		if(R[i] < l)
			continue;
		res = max(res, R[i]- prev - 1);
		prev = R[i];
	}
	res = max(res, r - prev);
	printf("%lld\n", res);
}
