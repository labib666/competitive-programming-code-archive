/*
UVa
11488 - Hyper Prefix Sets
DS - Trie
9 April 2014
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int id;
	node *next[2];
	node() {
		id = 0;
		next[0] = next[1] = NULL;
	}
} *root;

int t, n, ans;

void insert (string s) {
	int sz = s.size(), i, k;
	node *cur = root;
	
	for (i=0;i<sz;i++) {
		k = s[i]-'0';
		if (cur -> next[k] == NULL)
			cur -> next [k] = new node();
		cur = cur -> next[k];
		cur -> id += 1;
		ans = max (ans, (i+1)*(cur->id));
	}
	return;
}

void del (node *cur) {
	for (int i=0;i<2;i++) {
		if (cur -> next[i] == NULL) continue;
		del (cur -> next[i]);
	}
	delete cur;
}

int main() {
	int i;
	string s;
	
	cin >> t;
	while (t--) {
		ans = 0;
		root = new node();
		
		cin >> n;
		for (i=0;i<n;i++) {
			cin >> s;
			insert (s);
		}
		
		cout << ans << endl;
		del (root);
	}
	
	return 0;
}