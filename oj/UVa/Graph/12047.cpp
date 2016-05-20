/*
UVa
12047 - Highest Paid Toll
Graph
22 Feb 2014
*/

#include <bits/stdc++.h>
using namespace std;
#define inf 0x33333333
#define x first
#define y second

vector <int> v[10004], rv[10004], e[10004], re[10004];
int d[10004], rd[10004], uu[100004], vv[100004], ww[100004];
bool vis[10004], rvis[10004];
priority_queue < pair<int,int> > q;

int main() {
	int n, m, i, j, k, s, en, p, t, tc = 0;
	pair <int,int> cur;

	scanf ("%d", &t);
	while (tc < t) {
		tc++;
		for (i = 0; i < 10003; i++) {
			v[i].clear(); e[i].clear(); rv[i].clear(); re[i].clear();
			d[i] = -1; rd[i] = -1;
		}
		memset(vis, 0, sizeof(vis));
		memset(rvis, 0, sizeof(rvis));

		scanf ("%d%d%d%d%d", &n, &m, &s, &en, &p);

		for(int ii = 0; ii < m; ii++) {
			scanf ("%d%d%d", &i, &j, &k);
			uu[ii] = i, vv[ii] = j, ww[ii] = k;
			v[i].push_back(j);
			rv[j].push_back(i);
			e[i].push_back(k);
			re[j].push_back(k);
		}

		q.push(make_pair(0,s));
		while (!q.empty()) {
			cur = q.top(); q.pop();
			if (vis[cur.y]) continue;

			vis[cur.y] = 1;
			d[cur.y] = cur.x*(-1);

			for (i = 0; i < v[cur.y].size(); i++)
			{
				j = v[cur.y][i];
				if (vis[j]) continue;
				q.push(make_pair(cur.x-e[cur.y][i],j));
			}
		}

		q.push(make_pair(0,en));
		while (!q.empty()) {
			cur = q.top(); q.pop();
			if (rvis[cur.y]) continue;

			rvis[cur.y] = 1;
			rd[cur.y] = cur.x*(-1);

			for (i = 0; i < rv[cur.y].size(); i++)
			{
				j = rv[cur.y][i];
				if (rvis[j]) continue;
				q.push(make_pair(cur.x-re[cur.y][i],j));
			}
		}

		int ans = -1;

		for (i = 0; i < m; i++)
		{
			if (d[uu[i]] == -1 || rd[vv[i]] == -1) continue;
			if (d[uu[i]]+rd[vv[i]]+ww[i] <= p) ans = max (ans, ww[i]);
		}

		printf ("%d\n", ans);
	}

	return 0;
}
