#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int t, k, l, g;
	char s[100005];
	scanf("%d", &t);
	while(t--) {
		k = 1;
		l = g = 1;
		scanf("%s", s);
		for(int i = 0; i < strlen(s); i++) {
			if(s[i] == '>') 
				l = 1, g++;
			else if(s[i] == '<') 
				g = 1, l++;
			k = max(k, max(l, g));
	//		printf("%d %d %d\n", l, g, k);
		}
		printf("%d\n", k);
	}
	return 0;
}
