#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define N 111111

struct node {
	int count;
	node *left, *right;
};

int l, r, x;
int a[N], RM[N];
node *root[N];


node *create(int count, node *left, node  *right) {
	node *temp = (node *)malloc(sizeof(node));
	temp->count = count, temp->left = left, temp->right = right;
	return temp;
}

node *null = create(0, NULL, NULL);

node *insert(node *current, int l, int r, int w) {
	int m = (l+r)/2;
	if(l <= w && w < r) {
		if(l+1 == r) 
			return create(current->count+1, null, null);

		return create(current->count+1, insert(current->left, l, m, w), insert(current->right, m, r, w));
	}
	return current;
}

int query(node *a, node *b, int l, int r, int k) {
	int m = (l+r)/2;

	if(l == (r - 1))
		return l;

	int count = a->left->count - b->left->count;

	if(count >= k)
		return query(a->left, b->left, l, m, k);

	return query(a->right, b->right, m, r, k - count);
}

int main() {
	int n, m, t, maxi, count, k, range1, range2;
	maxi = 0;
	map <int, int> M;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		M[a[i]];
		root[i] = NULL;
	}
	for(map <int, int> :: iterator it = M.begin(); it != M.end(); it++) {
		M[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	null->left = null->right = null;
	root[0] = insert(null, 0, maxi, M[a[0]]);
	for(int i = 1; i < n ;i++) 
		root[i] = insert(root[i-1], 0, maxi, M[a[i]]);

	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &l, &r, &x);
		l--, r--, x--;
		int k = query(root[r], (!l ? null: root[l - 1]), 0, maxi, x - l + 1);
		if(RM[k] == a[x])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
