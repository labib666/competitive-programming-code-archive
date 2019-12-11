/*
USACO
3.2.6 - Sweet Butter
Dijkstra
22.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: butter
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
# include <cstring>
# include <queue>

# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007
# define pi 2*asin(1)
# define PII pair<int,int>
# define VI vector <int>
# define loop(a,s,e) for(a=s;a<e;a++)
# define rloop(a,s,e) for(a=s-1;a>=e;a--)

using namespace std;

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}

int d[805][805], m[805], n, p, c;
VI v[805], e[805];

void dijkstra (int a)
{
    int i, j, k;
    priority_queue < PII > q;
    bool vis[805];
    PII now;

    fill (vis+1, vis+p+1, 0);

    q.push (make_pair(0,a));

    while (!q.empty())
    {
        now = q.top();
        q.pop();

        if (vis[now.y]) continue;
        vis[now.y] = 1;
        d[a][now.y] = (-1)*now.x;

        for (i = 0; i < v[now.y].size(); i++)
        {
            k = v[now.y][i];
            if (vis[k]) continue;
            q.push(make_pair(now.x - e[now.y][i], k));
        }
    }

    return;
}

int main()
{
    //freopen ("butter.txt","r",stdin);
    freopen ("butter.in","r",stdin);
    freopen ("butter.out","w",stdout);

    int i, j, k;

    cin >> n >> p >> c;

    while (n--)
    {
        cin >> i;
        m[i]++;
    }

    while (c--)
    {
        cin >> i >> j >> k;
        v[i].pb (j);
        v[j].pb (i);
        e[i].pb (k);
        e[j].pb (k);
    }

    for (i = 1; i <= p; i++)
    {
        for (j = 1; j <= p; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }

    for (i = 1; i <= p; i++)
        dijkstra (i);


    int ans = inf;
    for (i = 1; i <= p; i++)
    {
        int now = 0;
        for (j = 1; j <= p; j++)
            now += m[j]*d[i][j];
        ans = min(ans, now);
    }

    cout << ans << endl;

    return 0;
}

