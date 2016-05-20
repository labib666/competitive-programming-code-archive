/*
ID: Labib Rashid
LANG: C++
TASK: rblock
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

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

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

struct data {
    ll pos, sum, par;
    bool operator < (const data &p) const {
        return sum > p.sum;
    }
};
data make_data (ll pos, ll sum, ll par)
{
    data d;
    d.pos = pos, d.sum = sum, d.par = par;
    return d;
}

bool vis[255];
vector <ll> v[255];
ll dist[255][255], par[255], n;
priority_queue <data> q;
stack <ll> path;

ll dijkstra()
{
    priority_queue < pair <ll,ll> > q2;
    bool vis2[255];
    pair <ll,ll> now, cur;
    ll i, j, k, ans;

    memset(vis2, 0, sizeof(vis));

    q2.push(make_pair(0,1));

    while (!q2.empty()) {
        now=q2.top();
        q2.pop();
        if (vis2[now.y]) continue;

        vis2[now.y] = 1;
        if (now.y == n) break;

        for (i = 0; i < v[now.y].size(); i++)
        {
            j = v[now.y][i];
            if (vis2[j]) continue;
            q2.push(make_pair(now.x-dist[now.y][j], j));
        }
    }
    return ans = now.x*(-1);
}

int main()
{
    //freopen ("2rblock.txt","r",stdin);
    freopen ("rblock.in","r",stdin);
    freopen ("rblock.out","w",stdout);

    ll i, j, k, indist, curdist, m, ans = 0;
    data d, now;

    cin >> n >> m;
    while (m--)
    {
        cin >> i >> j >> k;
        v[i].pb (j);
        v[j].pb (i);
        dist[i][j] = dist[j][i] = k;
    }

    d = make_data(1,0,0);
    q.push(d);

    while (!q.empty())
    {
        now = q.top();
        q.pop();
        if (vis[now.pos] == 1) continue;

        vis[now.pos] = 1;
        par[now.pos] = now.par;
        if (now.pos == n) break;

        for (i = 0; i<v[now.pos].size(); i++)
        {
            k = v[now.pos][i];
            if (vis[k]) continue;
            d = make_data(k, now.sum+dist[now.pos][k], now.pos);
            q.push(d);
        }
    }

    indist = now.sum;

    path.push(n);
    while (par[path.top()] != 1) {
        path.push(par[path.top()]);
    }

    i = 1;
    while (!path.empty())
    {
        j = path.top();
        path.pop();

        dist[i][j] *= 2;
        dist[j][i] *= 2;

        curdist=dijkstra();
        ans = max(ans, curdist-indist);

        dist[i][j] /= 2;
        dist[j][i] /= 2;
        i = j;
    }

    cout << ans << endl;

    return 0;
}
