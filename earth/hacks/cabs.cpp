#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;

int find(int arr[], int dep[], int n) {
   int cur = 1, result = 1, i = 1, j = 0;
   while (i < n && j < n) {
      if (arr[i] <= dep[j]) {
          cur++, i++;
          result = max(cur, result);
      }
      else  {
          cur--;
          j++;
      }
   }
   return result;
}
int main() {
	int n, ans, k, at = 0, bt = 0, hh, mm;
	int a[100005], b[100005];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &hh, &mm);
		a[i] = hh*100 + mm;
		scanf("%d%d",&hh, &mm);
		b[i] = hh*100 + mm;
	}
	sort(a, a+n);
	sort(b, b+n);
	printf("%d\n", find(a, b, n));	
	return 0;
}
