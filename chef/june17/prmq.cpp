#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
map<int, int> powers[100005];
int lprime[1000005], a[100005], primes[100005], len, n, qn, l, r, x, y;
 
void sieve() {
	lprime[1] = 1;
	for(ll i = 2; i <= 1000000; i++) {
		if(!lprime[i]) {
			primes[len++] = i;
			lprime[i] = i;
			for(ll j = i; (i*j) <= 1000000; j++) {
				if(!lprime[i*j]) lprime[i*j] = i;
			}
		}
	}
	primes[len++] = 1000003;
}
 
void update(int idx ,int val, int n){
    map<int, int> factors;
	while(val > 1) {
		factors[lprime[val]]++;
		val /= lprime[val];
	}
	while (idx <= n) { 
		for(map<int,int>::iterator it = factors.begin(); it != factors.end(); it++)
			powers[idx][it->first] += it->second;
        idx += (idx & -idx);
    }
}
 
int read(int idx, int x, int y, int n) {	
	int ans = 0;
	while (idx > 0) { 
		map<int, int>:: iterator it = powers[idx].lower_bound(x);
		map<int, int>:: iterator jt = powers[idx].lower_bound(y);
		if(it == powers[idx].begin()) {
			if(jt == it) {
				if(jt->first == y)
					ans += jt->second;
				idx -= (idx & -idx);
				continue;
			}
			if(jt->first != y) 
				jt--;
			ans += jt->second;
			idx -= (idx & -idx);
			continue;
		}
		if(jt->first != y) 
			jt--;
		it--;
		ans += jt->second - it->second;
        idx -= (idx & -idx);
    }
	return ans;
}
 
void optimize() {
	for(int i = 1; i <= n; i++) {
		map<int, int>:: iterator it = powers[i].begin(), jt;
		while(it != powers[i].end()) {
			if(it == powers[i].begin()) {
				jt = it;
				it++;
			}
			else {
				it->second += jt->second;
				it++;
				jt++;
			}
		}
 
	}
}
int main() {
	sieve();
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		update(i, a[i], n);
	}
	optimize();
	scanf("%d", &qn);
	for(int i = 0; i < qn; i++) {
		scanf("%d%d%d%d", &l, &r, &x, &y);
		printf("%d\n", read(r, x, y, n) - read(l-1, x, y, n));
	}
	return 0;
}
