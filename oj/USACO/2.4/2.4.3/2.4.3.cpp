/*
ID: Labib Rashid
LANG: C++
TASK: cowtour
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

int bitcount (ll a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}


pair <double, double> p[155];
bool v[155][155];
double md [155];
int n, nc, c[155];

void dfs (int a, int t)
{
    c[a] = t;

    for (int i = 0; i < n; i++)
    {
        if (v[a][i] && !c[i])
            dfs (i,t);
    }

    return;
}

void mdist (int b)
{
    priority_queue < pair < double, int > > q;
    bool vis [155];
    double ans;

    int i, j, k;
    double a;
    pair <double, int> now;

    fill (vis, vis + n, 0);
    ans = 0.0;

    q.push (make_pair (0.0, b));
    while (!q.empty())
    {
        now = q.top();
        q.pop();

        if (vis[now.y]) continue;
        vis[now.y] = 1;
        ans = now.x;

        for (i = 0; i < n; i++)
        {
            if (!v[now.y][i]) continue;
            if (vis[i]) continue;

            a = (p[now.y].x - p[i].x)*(p[now.y].x - p[i].x) + (p[now.y].y - p[i].y)*(p[now.y].y - p[i].y);
            a = sqrt (a);

            q.push (make_pair (now.x-a, i));
        }
    }

    md[b] = (-1) * ans;
    return;
}

int main()
{
    //freopen ("cowtour.txt","r",stdin);
    freopen ("cowtour.in","r",stdin);
    freopen ("cowtour.out","w",stdout);

    int i, j, k;
    double a, b, ans;
    string s;

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    for (i = 0; i < n; i++)
    {
        cin >> s;
        for (j = 0; j < n; j++)
            if (s[j] == '1')
                v[i][j] = 1;
    }

    nc = 1;
    for (i = 0; i < n; i++)
    {
        if (!c[i]) {
            dfs (i, nc);
            nc++;
        }
    }

    for (i = 0; i < n; i++)
        mdist(i);

    ans = 1e12;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i] == c[j]) continue;

            a = (p[j].x - p[i].x)*(p[j].x - p[i].x) + (p[j].y - p[i].y)*(p[j].y - p[i].y);
            a = sqrt (a);

            ans = min (ans, a+md[i]+md[j]);
        }
    }

    for (i = 0; i < n; i++)
        ans = max (ans, md[i]);

    printf ("%.6lf\n", ans);

    return 0;
}

