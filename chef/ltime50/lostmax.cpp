#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	ll t, a[64], n;
	char s[128];
	scanf("%lld", &t);
	while(t--) {
		scanf("%[^\n]", s);
		n = 0;
		for(int i = 0; i < strlen(s); i+=2) {
			a[n++] = s[i] - '0';
		}
		printf("sfka\n");
	} 
	return 0;
}
