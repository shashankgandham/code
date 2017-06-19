#include <bits/stdc++.h>
using namespace std;
int a[256];
void seive() {
	a[0] = 1;
	for(int i = 1; i <= 100; i++) 
		a[i] = a[i-1] + 3;
}
int main() {
	int t, n;
	scanf("%d", &t);
	seive();
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
 
