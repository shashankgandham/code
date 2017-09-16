#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int l[5005], r[5005], a[5005], n, prexor[5005], visit[5005], dp[5005];
int solve(int idx) {
    if(idx > n || dp[idx] != -1)
        return dp[idx];
    
	int start = l[a[idx]], end = r[a[idx]], val = prexor[end]^prexor[start-1];
    
	if(start == idx) {
        int j = end, i = idx;
        while(i < end && l[a[i]] >= start) 
                j = max(j, r[a[i++]]);
        if(i == end)
            return dp[idx]= max(val + solve(j + 1), solve(idx + 1));
    }
	return dp[idx]= solve(idx+1);
}
int main() {  
    scanf("%d", &n);
	for(int i = 1; i <= n; i++){
        dp[i] = -1;
		scanf("%d", &a[i]);
		if(!l[a[i]])
			l[a[i]] = i;    
		r[a[i]] = i;
        
		prexor[i] = prexor[i-1];
		if(!visit[a[i]])
			prexor[i] ^= a[i];
		
		visit[a[i]] = 1; 
	}
	printf("%d\n", solve(1));
	return 0;
}
