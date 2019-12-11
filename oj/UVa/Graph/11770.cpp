/*
UVa
11770 - Lighting Away
Graph
24 Feb 2014
*/

#include <bits/stdc++.h>
using namespace std;

int rec[10004], trig[10004];
vector <int> v[10004], rv[10004];

void trigger (int bulb)
{
	trig[bulb] = 1;
	for (int i=0; i<v[bulb].size(); i++)
	{
		int j = v[bulb][i];
		if (trig[j]) continue;
		trigger (j);
	}
	return;
}

bool recurse (int pos)
{
	if (!trig[pos]) return 1;
	rec[pos] = 1;
	for (int i = 0; i < rv[pos].size(); i++)
	{
		int j = rv[pos][i];
		if (rec[j]) continue;
		if (recurse(j)) return 1;
	}
	return 0;
}


int main() {
	int t, tc = 0, n, m, i, j, k, ans;
	scanf ("%d", &t);
	while (tc < t) {
		tc++;
		scanf ("%d%d", &n, &m);
		for (i=1; i<=n; i++) {
			rv[i].clear();
			v[i].clear();
			rec[i] = trig[i] = 0;
		}
		while (m--) {
			scanf ("%d%d", &i, &j);
			v[i].push_back(j);
			rv[j].push_back(i);
		}
		for (i = 1, ans = 0; i <= n; i++) {
			if (trig[i]) continue;
			trigger (i);
			if (recurse(i)) continue;
			ans++;
		}
		printf ("Case %d: %d\n", tc, ans);
	}
	return 0;
}