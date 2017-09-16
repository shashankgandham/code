#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int r = 0, c = 0, d = 0, ans = 0;
	char s[16][16];
	for(int i = 0; i < 10; i++)
		scanf("%s", s[i]);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(s[i][j] == 'X') r++;
			else ans = max(r, ans), r = 0;
			if(s[j][i] == 'X') c++;
			else ans = max(c, ans), c = 0;
			if(i <= 
		}
	} 
	
	return 0;
}
