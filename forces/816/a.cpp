#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool check(int m, int n) {
	if(m%10 == n/10 && m/10 == n%10)
		return true;
	else 
		return false;
} 
int main() {
	int n, h, m, k = 0;
	char s[8], hr[4], min[4];
	scanf("%s", s);
	hr[0] = s[0], hr[1] = s[1], hr[2] = 0;
	min[0] = s[3], min[1] = s[4], min[2] = 0;
	h = stoi(hr);
	m = stoi(min);
	while(true) {
		if(check(h, m)) {
			printf("%d\n", k);
			break;
		}
		else {
			m++;
			if(m == 60) {
				m = 0;
				h++;
				if(h == 24)
					h = 0;
			}
			k++;
		}
	}
	return 0;
}
