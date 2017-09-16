#include <bits/stdc++.h>
#define N 1e5 + 5
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
ll n, A, B, cnt[1000005], x[100005];
int main() {
	scanf("%lld%lld", &n, &A);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		if(x[i] == A)
			cnt[A]++;
		else if(cnt[x[i]] != -1 && cnt[A] <= cnt[x[i]])
			cnt[x[i]]++;
		else if(cnt[A] > cnt[x[i]])
			cnt[x[i]] = -1;
	}
	for(int i = 1; i <= 1000000; i++) {
		if(cnt[i] != -1 && i != A) {
			if(cnt[i] >= cnt[A]) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
