#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int x1, y1, x2, y2, x, y;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf("%d%d", &x, &y);
	if(!(abs(x1 - x2)%x) && !(abs(y1 - y2)%y)) {
		if(!(abs(abs(x1 - x2)/x - abs(y1 - y2)/y)%2))
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("NO\n");
	return 0;
}
