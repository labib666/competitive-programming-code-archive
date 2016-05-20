/*
UVa
796 - Critical Links
Graph
23.1.2014
*/
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9
using namespace std;

set <PII> a;
set <PII>::iterator it;
VI v[10004];
int c[10004], vis[10004];

int dfs (int u, int par, int depth)
{
	vis[u] = depth;
	int sum = 0, j;
	for (int i = 0; i < v[u].size(); i++)
	{
		int vv = v[u][i];
		if (vv == par)continue;

		if (vis[vv])
		{
			if (vis[vv] > vis[u]) continue;
			c[u]++; c[vv]--;
			continue;
		}

		j = dfs(vv,u,depth+1);
		if (j) {sum += j;continue;}

		int u1, v1;
		u1 = u, v1 = vv;
		if (u1 > v1) swap (u1,v1);
		a.insert(make_pair(u1,v1));
	}

	return sum+c[u];
}

int main() {
	int n, i, j, k, u, vv;
	char str[100];

	while (scanf ("%d",&n)!=EOF)
	{
		for (i=0; i<n; i++)
			v[i].clear();
        memset (c, 0, sizeof (c));
		memset (vis, 0, sizeof(vis));
		a.clear();

		for (i = 0; i < n; i++)
		{
			scanf ("%d%s", &u,str);
			stringstream ss; char ch;
			ss << str;
			ss >> ch;
			ss >> k;
			for (j = 0; j < k; j++){
				scanf ("%d", &vv);
				v[u].pb (vv);
			}
		}


		for (j = 0; j < n; j++)
		{
			if (vis[j]) continue;
			dfs (j,-1, 1);
		}

		printf ("%d critical links\n", a.size());
		for (it=a.begin(); it != a.end(); it++)
		{
			PII p = *it;
			printf ("%d - %d\n", p.x, p.y);
		}
		cout << endl;
	}

	return 0;
}
