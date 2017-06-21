#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct trie{
	int num;
	trie *left, *right;
};	 
trie *create() {
	trie *node = (trie *)malloc(sizeof(trie));
	node->num = 0;
	node->left = node->right = NULL;
	return node;
}
int getbit(int num, int pos) {
	return (num >> (31 -pos)) & 1;
}
void insert(trie *root, int num) {
	trie *temp = root;
	for(int i = 0; i < 32; i++) {
		if(getbit(num, i)) {
			if(temp->right == NULL) 
				temp->right = create();
			temp->right->num++;
			temp = temp->right;
		}
		else {
			if(temp->left == NULL) 
				temp->left = create();
			temp->left->num++;
			temp = temp->left;
		}
	}
}
void remove(trie *root, int num) {
	trie *temp = root;
	for(int i = 0; i < 32; i++) {
		if(getbit(num, i)) {
			temp->right->num--;
			temp = temp->right;
		}
		else {
			temp->left->num--;
			temp = temp->left;
		}
	}
}
int search(trie *root, int r, int l) {
	trie *temp = root;
	int ans = 0;
	for(int i = 0; i < 32; i++) {
		if(temp == NULL)
			return ans;
		if(getbit(r, i)) {
			if(getbit(l, i) && temp->left != NULL)
				ans += temp->left->num;
			temp = temp->right; 
		}
		else {
			if(getbit(l, i) && temp->right != NULL) 
				ans += temp->right->num;
			temp = temp->left;
		}
	}
	return ans;
}
int main() {
	int n, q, r, l;
	trie *root = create();
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &q, &r);
		if(q == 1)
			insert(root, r);
		else if(q == 2)
			remove(root, r);
		else {
			scanf("%d", &l);
			printf("%d\n", search(root, r^l, l));
		} 
	} 
	return 0;
}
