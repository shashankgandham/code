#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef struct combined{
	int len, ch;
}combined;

typedef struct 

int main() {
	int n, q, m[2048], l = 0;
	char s[200005], c[2048];
	freq x[200005];
	scanf("%d", &n);
	scanf(" %s", s);
	scanf("%d", &q);
	for(int i = 0; i < n; i++) {
		if(!i) {
			x[l].len++;
			x[l].ch = s[i] - 'a';
		}
		else {
			if(s[i] == s[i-1])
				x[l].len++;
			else {
				x[++l].ch = s[i] - 'a';
				x[l].len++;
			}
		}
	}
	for(int i = 0; i < q; i++) {
		scanf("%d %c", m[i], c[i]);
	}
	return 0;
}
