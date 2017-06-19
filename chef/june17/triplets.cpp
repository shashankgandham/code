#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;
 
ll A[100005], a[100005], B[100005], b[100005], C[100005], c[100005];
 
ll solve(ll p, ll q, ll r) {
	ll nx, ny, nz, ans = 0;;
	for(int i = 0; i < q; i++) {
		nx = upper_bound(A, A + p, B[i]) - A;
		nz = upper_bound(C, C + r, B[i]) - C;
		if(!nx || !nz) continue;
		ans += (((a[nx - 1]*nz + c[nz - 1]*nx)%MOD)*B[i])%MOD;
		ans = ans%MOD;
		ans += (((nx*nz)%MOD)*((B[i]*B[i])%MOD))%MOD;
		ans = ans%MOD;
		ans += (a[nx-1]*c[nz-1])%MOD;
		ans = ans%MOD;
	}
	return ans;
}
 
int main() {
	ll t, p, q, r; 
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld%lld", &p, &q, &r);
		for(int i = 0; i < p; i++) 
			scanf("%lld", &A[i]);
		for(int i = 0; i < q; i++) 
			scanf("%lld", &B[i]);
		for(int i = 0; i < r; i++) 
			scanf("%lld", &C[i]);
		
		sort(A, A+p);
		sort(B, B+q);
		sort(C, C+r);
 
		a[0] = A[0], b[0] = B[0], c[0] = C[0];
		for(int i = 1; i < p; i++) {
			a[i] = a[i-1] + A[i];
			a[i] = a[i]%MOD;
		}
		for(int i = 1; i < q; i++) {
			b[i] = b[i-1] + B[i];
			b[i] = b[i]%MOD;
		}
		
		for(int i = 1; i < r; i++) {
			c[i] = c[i-1] + C[i];
			c[i] = c[i]%MOD;
		}
		printf("%lld\n", solve(p, q, r));	
	}
	return 0;
}
