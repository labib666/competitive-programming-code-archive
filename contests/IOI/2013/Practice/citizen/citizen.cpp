#include "citizen.h"
/*
ID: Labib Rashid
LANG: C++
TASK:
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

bool vis [150];
PII p[150];
int c[150];

int countries(int n, int *l, int *w) {

    if (!n) return 0;

    int i, j, k, a, b, t, m;

    memset (vis, 0, sizeof (vis));

    for (i = 0; i < n; i++)
    {
        p[i].x = w[i], p[i].y = l[i];
    }

    sort (p, p+n);
    reverse (p, p+n);

    //cout <<  endl << " sorted data " << endl << endl;

    //for ( i = 0;i < n; i++)
        //cout << i << "  "  << p[i].x << " " << p[i]. y << endl;

    //cout << endl << endl;

    a = inf;
    b = inf;

    while (a)
    {

        memset (c, -1, sizeof (c));

        for (i = 0; i < n; i++)
        {
            if (vis[i] || b < p[i].y) continue;
            c[i] = 0;

            for (j = 0; j < n; j++)
            {
                if (vis [j] || i == j ) continue;

                if (p[i].x >= p[j].y) c[i]++;
            }
        }

        m = -1, t = 0;

        for (i = 0; i < n; i++)
        {
            //cout << " i = " << i << "  >> " << c[i] << endl;
            if (c[i] > m)
            {
                m = c[i];
                t = i;
            }
        }

        a = m;
        b = min(b,p[t].x);
        vis[t] = 1;

        //cout << "visited >> " << t << endl;
    }

    int ans = 0;

    for (i = 0; i < n; i++)
        if (vis[i]) ans++;

    return ans;
}
