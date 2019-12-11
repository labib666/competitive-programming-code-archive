/*
UVa
11362 - Phone List
DS - trie (with linked list + pointers)
9 April 2014
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	bool id;
	node *next [11];
	node () {
		id = 0;
		for (int i=0;i<10;i++)
			next[i] = NULL;
	}
} *root;

bool fail;
string s[10004];

void insert (string str, int len) {
	node *cur = root;
	for (int i=0;i<len;i++) {
		int k = str[i]-'0';
		if (cur -> next[k] == NULL) {
			cur -> next[k] = new node();
		}
		cur = cur -> next[k];
		if (cur -> id) {
			fail = 1;
			return;
		}
	}
	cur -> id = 1;
	return;
}

void del(node *cur) {
	for (int i=0;i<10;i++) {
		if (cur -> next[i] == NULL) continue;
		del (cur -> next[i]);
	}
	delete cur;
	return;
}

bool cmp (string s1, string s2) {
	return (int)s1.size() < (int)s2.size();
}

int main() {
	int sz, i, t, n;

	scanf ("%d", &t);

	while (t--) {
		fail = 0;
		root = new node();

		scanf ("%d", &n);

		for (i=0;i<n;i++)
			cin >> s[i];

		sort (s, s+n, cmp);

		for (i=0;i<n;i++) {
			if (fail) break;
			sz = s[i].size();
			insert (s[i], sz);
		}

		del (root);
		(fail) ? cout << "NO\n" : cout << "YES\n";
	}

	return 0;
}
