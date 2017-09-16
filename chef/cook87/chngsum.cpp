#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
ll n, l[1000005], rmin[1000005], dpmin[1000005], lmax[1000005], dpmax[1000005], ans;
const ll MOD = 1000000007;
int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &l[i]);
	
	stack<ll> st;
    rmin[n] = n+1;
    st.push(n);
    for(int i = n-1; i > 0; i--){
        while(!st.empty() && l[st.top()] >= l[i])
            st.pop();

        if(st.empty())
			rmin[i] = n+1;
        
		else 
			rmin[i] = st.top();
        st.push(i);
    }
	dpmin[n] = l[n];
	for(int i = n-1; i > 0; i--) {
		dpmin[i] = (rmin[i] - i)*l[i] + dpmin[rmin[i]];
		dpmin[i] %= MOD;
	}
	while(!st.empty())
		st.pop();
	
    lmax[1] = 0;
    st.push(1);
    for(int i = 2; i <= n; i++){
        while(!st.empty() && l[st.top()] <= l[i])
            st.pop();

        if(st.empty())
			lmax[i] = 0;
        
		else 
			lmax[i] = st.top();
        st.push(i);
    }
	dpmax[1] = l[1];
	
	for(int i = 2; i <= n; i++) {
		dpmax[i] = (i - lmax[i])*l[i] + dpmin[lmax[i]];
		dpmax[i] %= MOD;
	}
	for(int i = n; i >= 1; i--) {
		dpmin[i] += dpmin[i+1];
		dpmin[i] %= MOD;
	}
	for(int i = 1; i < n; i++) {
		ans += dpmax[i]*dpmin[i+1];
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
