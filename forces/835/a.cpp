#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int s, v1, v2, t1, t2;
	double a, b;
	scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
	a = 2*t1 + s*v1, b = 2*t2 + s*v2;
	if(a < b)
		printf("First\n");
	else if(a > b)
		printf("Second\n");
	else
		printf("Friendship\n");
	return 0;
}
