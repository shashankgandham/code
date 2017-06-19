#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, q, m, moves[32][2048], l, r, ans[32][1502];

int main() {
	char s[2048], c;
	scanf("%d", &n);
	scanf(" %s", s);
	scanf("%d", &q);
	for(int i = 0; i < strlen(s); i++) {
		for(int j = 0; j < 26; j++) {
			if(s[i] - 'a' != j)
				moves[j][i]++;
		}
	}
	for(int i = 0; i < 26; i++) {
		for(int j = strlen(s); j > 0; j--) {
			moves[i][j-1] += moves[i][j];
		}
	}
	for(int i = 0; i < 26; i++) {
		for(int j = 1; j <= n; j++) {
			l = 0, r = 1, c -= 'a';
			while(r <= strlen(s)) {
				if(l > r)
					break;
				if(moves[i][l] - moves[i][r] <= j) {
					ans[i][j] = max(r - l, ans[i][j]);
					r++;
				}
				else
					l++;
			}
		}
	}
	for(int i = 0; i < q; i++) {
		scanf("%d %c", &m, &c);
		printf("%d\n", ans[c - 'a'][m]);
	}
	return 0;
}
