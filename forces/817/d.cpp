#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef struct node{
	ll minn, maxx;
}node;
ll n, a[1000005], masum, misum, k;
node tree[4000005];

void build(int node, int start, int end) {
	if(start == end) {
		tree[node].minn = start;
		tree[node].maxx = start;
	}
	else {
		int mid = (start + end)/2;
		build(node*2, start, mid);
		build(node*2 + 1, mid + 1, end);
		
		if(a[tree[node*2].minn] < a[tree[node*2 + 1].minn])
			tree[node].minn = tree[node*2].minn;
		else
			tree[node].minn = tree[node*2 + 1].minn;
		
		if(a[tree[node*2].maxx] > a[tree[node*2 + 1].maxx])
			tree[node].maxx = tree[node*2].maxx;
		else
			tree[node].maxx = tree[node*2 + 1].maxx;
	}
}
int minn(int node, int l, int r, int start, int end) {
	if(l > r || l > end || r < start)
		return 0;

	if(l >= start && r <= end)
		return tree[node].minn;
	
	int n1 = minn(2*node, l, (l + r)/2, start, end);
	int n2 = minn(2*node + 1, (l + r)/2 + 1, r, start, end);
	if(!n1 || !n2) 
		return max(n1, n2);
	return (a[n1] < a[n2])? n1: n2;  
}

int maxx(int node, int l, int r, int start, int end) {
	if(l > r || l > end || r < start)
		return 0;

	if(l >= start && r <= end)
		return tree[node].maxx;
	
	int n1 = maxx(2*node, l, (l + r)/2, start, end);
	int n2 = maxx(2*node + 1, (l + r)/2 + 1, r, start, end);
	if(!n1 || !n2) 
		return max(n1, n2);
	return (a[n1] > a[n2])? n1: n2;  

}
ll smax(int l, int r) {
	if(l > r) return 0;
	int c = maxx(1, 1, n, l, r);
	return (ll)(c - l + 1)*(r-c+1)*a[c] + smax(l, c - 1) + smax(c + 1, r);
}
ll smin(int l, int r) {
	if(l > r) return 0;
	int c = minn(1, 1, n, l, r);
	return (ll)(c - l + 1)*(r-c+1)*a[c] + smin(l, c - 1) + smin(c + 1, r);
}
int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%lld", &a[i]);
	build(1, 1, n);
	printf("%lld\n", smax(1, n)	- smin(1, n));
	return 0;
}
