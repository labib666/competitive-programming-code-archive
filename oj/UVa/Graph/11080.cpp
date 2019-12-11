/*
UVa
11080 - Placing the Guards
Graph - coloring
14 feb, 2014
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

int flag[205];
VI v[205];

PII dfs (int pos, int par, int col)
{
    int i, j, k;
    PII p = (col%2) ? make_pair(1,1) : make_pair(0,1); PII cur;

    flag[pos] = col;
    for (i=0; i<v[pos].size(); i++){
        k = v[pos][i];

        if (k == par) continue;
        if (flag[pos] == flag[k]) return make_pair(-1,-1);
        if (flag[k]) continue;

        cur = dfs(k,pos,col%2+1);
        if (cur.x == -1) return make_pair(-1,-1);
        p.x += cur.x, p.y += cur.y;
    }
    return p;
}

int check (int n)
{
    int ans = 0, i, j, k;
    PII p;

    for (i = 0; i < n; i++)
    {
        if (flag[i]) continue;
        else {
            p = dfs (i, -1, 1);
            if (p.x == -1) return -1;
            if (p.y == 1) ans += 1;
            else ans +=  min(p.x, p.y-p.x);
        }
    }
    return ans;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int t, tc = 0, n, m, i, j, k;

    scanf ("%d",&t);
    while (tc < t) {

        tc++;
        memset(flag, 0, sizeof (flag));
        for (i=0;i<204;i++) v[i].clear();

        scanf ("%d%d",&n,&m);

        for (i=0;i<m;i++) {
            scanf ("%d%d",&j,&k);
            v[j].pb (k);
            v[k].pb (j);
        }

        k = check (n);
        if (k == -1) printf ("-1\n");
        else printf ("%d\n",k);
    }


    return 0;
}
