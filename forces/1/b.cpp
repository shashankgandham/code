#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, row, col, i, j, k;
	char s[32], r[32], c[32];
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		if(s[0] == 'R' && s[1] >= '0' && s[1] <= '9' && (find(s, s+strlen(s), 'C') - s != strlen(s))) {
			i = j = 0;
			while(s[++i] != 'C') r[i - 1] = s[i];
			r[i - 1] = 0;
			j = 0;
			while(s[++i] != 0) c[j++] = s[i];
			c[j] = 0;
			row = stoi(r), col = stoi(c);
			i = j = 0;
			while(col) {
				j = (col - 1)%26;
				c[i++] = j + 65;
				col = (col - j)/26;
			}
			c[i] = 0;
			reverse(c, c + strlen(c));
			printf("%s%s\n",c,r); 
		} 
		else{
			row = 0, col = 0, j = 0, k = 0;
			for(int i = 0; i < strlen(s); i++) {
				if(s[i] >= '0' && s[i] <= '9') {
					r[j++] = s[i];
				}
				else k++;
			}
			r[j] = 0;
			row = stoi(r);
			for(int i = 0; i < k; i++) {
				col += (s[i] - 'A' + 1)*pow(26, k-i-1);
			}
			printf("R%dC%d\n", row, col);	
				
		}
	}	
}
