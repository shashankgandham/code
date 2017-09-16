#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int n, k = 0;;
	char s[128];
	scanf("%d", &n);
	scanf("%s", s);
	s[n] = '0', s[n+1] = 0;
	for(int i = 0; i <= n; i++) {
		if(s[i] == '1') k++;
		else {
			printf("%d", k);
			k = 0;
		}
	}
	printf("\n");
	return 0;
}
