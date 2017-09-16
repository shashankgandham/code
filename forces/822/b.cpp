#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int n, m, minc, start, currc;
	char s[1024], t[1024];
	scanf("%d%d", &n, &m);
	scanf("%s%s", s, t);
	minc = INT_MAX;
	for(int i = 0; i <= m - n; i++) {
		currc = 0;
		for(int j = 0; j < n; j++) {
			if(t[i + j] != s[j])
				currc++;
		}
		if(currc < minc) {
			minc = currc;
			start = i;
		}
	}
	printf("%d\n", minc);
	for(int i = 0; i < n; i++) {
		if(s[i] != t[i + start])
			printf("%d ", i + 1);
	}
	printf("\n");
	return 0;
}
