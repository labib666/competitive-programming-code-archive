#include "birthday.h"
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

ll gcd (ll a, ll b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

ll bitcount (ll a)
{
    ll i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}

ll a[1005], b[1005], c[1005];
map < pair <pair <ll, ll>,pair <ll, ll> > , bool > m;

int pieces(int R, int N, int *X1, int *Y1, int *X2, int *Y2) {

    ll i, j, k, n, r, x1[1005], y1[1005], x2 [1005], y2[1005];

    n = N, r = R;
    for (i = 0; i < n; i++)
        x1[i] = X1[i], x2[i] = X2[i], y1 [i] = Y1[i], y2[i] = Y2[i];

    for (i = 0; i < n; i++)
    {
        a[i] = y1[i] - y2[i];
        b[i] = (-1)*(x1[i]-x2[i]);
        c[i] = (-1) * (x1[i]*a[i] + y1[i]*b[i]);
    }

    int ans = n + 1;

    for (i = 0; i < n; i++)
    {
        m.clear();

        for (j = 0; j < i; j++)
        {
            if (i == j) continue;

            if (a[i]*b[j] == a[j]*b[i]) continue;

            ll p, q1, q2;

            p = a[i]*b[j] - a[j]*b[i];

            q1 = b[i]*c[j] - b[j]*c[i];

            q2 = c[i]*a[j] - c[j]*a[i];

            if ( (q1*q1 + q2*q2) > p*p*r*r )  continue;

            ll g,p1;
            pair <ll, ll> z1, z2;

            p1 = p;

            g = gcd (abs(q1),abs(p));
            if (q1 < 0 && p < 0) q1 *= (-1), p *= (-1);
            z1 = make_pair (q1/g, p/g);

            p = p1;

            g = gcd (abs(q2),abs(p));
            if (q2 < 0 && p < 0) q2 *= (-1), p *= (-1);
            z2 = make_pair (q2/g, p/g);

            if (m[make_pair(z1,z2)]) continue;
            m[make_pair(z1,z2)] = 1;
            ans++;
        }
    }
    return ans;
}
