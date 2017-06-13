#include <bits/stdc++.h>
using namespace std;
int n, m, curr, mins, total[128][8], l, r;

int solve(int curr, int floor) {
	if(floor >= n) {
		if(curr) return total[floor][2];
		else return total[floor][0];
	}
	if(curr) return min((total[floor][2] + solve(0, floor + 1)), 
			(total[floor][3] + solve(1, floor + 1)));
	else return min((total[floor][0] + solve(0, floor + 1)), 
			(total[floor][1] + solve(1, floor + 1)));
}

int main() {
	char s[128];
	scanf("%d%d", &n, &m);
	m = m + 2;
	for(int i = n; i > 0; i--) {
		l = r = 0;
		scanf(" %s", s);
		for(int j = 0; j < strlen(s); j++) {
			if(s[j] == '1') {
				if(i == n || n == 1) {
					total[i][0] = j + 1;
					total[i][1] = j + 1;
					if(n == 1) total[i][0]--, total[i][1]--;
				}
				else if(i == 1) {
					total[i][0] = 2*j;
					total[i][1] = strlen(s) - 1;
				} 
				else {
					total[i][0] = 2*j + 1;
					total[i][1] = strlen(s);
				}
			} 
			if(s[strlen(s) - j - 1] == '1') {
				if(i == n) {
					total[i][2] = j + 1;
					total[i][3] = j + 1;
				}
				else {
					total[i][2] = strlen(s);
					total[i][3] = 2*j + 1;
				}
			}
		}
		if(total[i][0] == 0) {
			if(i == n) n--;
			else if(i != 1){
				total[i][0] = 1;
				total[i][1] = strlen(s);
				total[i][2] = strlen(s);
				total[i][3] = 1;
			}
		}
		//printf("%d %d %d %d\n", total[i][0], total[i][1], total[i][2], total[i][3]);
	}
	printf("%d\n", solve(0, 1));
}
