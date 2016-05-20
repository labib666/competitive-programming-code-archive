/*
USACO
3.3.2 - Shopping Offers
DP
6 Feb,2014
/*
ID: ewmahad1
PROB: shopping
LANG: C++
*/
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

struct data {
	int v[5];
};

data mis(data a1, data a2)          // a1 - a2 = ?
{
	int i; data b;
	for (i=0;i<5;i++) b.v[i]=a1.v[i]-a2.v[i];
	return b;
}

bool is_valid (data a)              // are all the values of the data non-negative?
{
	for (int i=0;i<5;i++) if (a.v[i]<0) return 0;
	return 1;
}

data pac[100];                      // valid package list
vector < pair<int,int> > init[100]; // all packages
int id[1000];						// id according to the things needed ( if not needed, id=(-1) )
int price[5];						// individual price of the needed products
int dp[100][6][6][6][6][6], cnt, all;
int inprice[100], pacpr[100];       // intial package price & finally chosen package price

data initialise()
{
	data n; for (int i=0;i<5;i++) n.v[i]=0;

	cnt=0; memset(id,-1,sizeof(id));
	memset(dp,-1,sizeof(dp));

	int u, v, w;

	cin >> u;
	for (v=0;v<u;v++) {
		cin >> w >> n.v[v] >> price[v];
		id[w]=v;
	}

	for (v=0;v<all;v++){
		bool fail=0;
		for (u=0;u<init[v].size();u++){
			int jj = id[init[v][u].x];
			if (jj==-1) {fail=1;break;}        // has unnecessary product
		}
		if (fail) continue;
		for (u=0;u<5;u++)pac[cnt].v[u]=0;
		for (u=0;u<init[v].size();u++){
			int jj = id[init[v][u].x];
			pac[cnt].v[jj]=init[v][u].y;
		}
		pacpr[cnt] = inprice[v];
		cnt++;
	}
	return n;
}

int solve (int at, data c){

	if (at == cnt) {
		int ret = 0;
		for (int i=0;i<5;i++)
			ret += c.v[i]*price[i];
        return ret;
	}

	int &ret = dp[at][c.v[0]][c.v[1]][c.v[2]][c.v[3]][c.v[4]];

	if (ret != -1) return ret;

	ret = solve (at+1,c);

	data bb = mis(c,pac[at]);
	if (is_valid(bb)) ret = min (ret, pacpr[at]+solve(at,bb));

	return ret;
}

int main()
{
    //freopen ("shopping.txt", "r", stdin);
	freopen ("shopping.in", "r", stdin);
	freopen ("shopping.out", "w", stdout);

	int i, j, k, u, v, item;
	data dd;

	cin >> all;
	for (i = 0; i < all; i++)
	{
		cin >> k;
		for (j=0;j<k;j++)
		{
			cin >> u >> v;
			init[i].push_back(make_pair(u,v));
		}
		cin >> inprice[i];
	}

	dd = initialise();

	cout << solve(0,dd) << endl;

	return 0;
}
