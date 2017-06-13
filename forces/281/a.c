#include <bits/stdc++.h>
using namespace std;

int main() {
	char s[1024];
	scanf("%s", s);
	if(s[0] > 'Z') s[0] = s[0] - 'a' + 'A';
	printf("%s\n", s);
	return 0;
}