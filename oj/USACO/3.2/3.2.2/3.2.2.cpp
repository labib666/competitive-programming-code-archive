/*
USACO
3.2.2 - Stringsobits
dp, bitwise op
24.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: kimbits
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

ll c[35][35], dp[35][35];

ll C(ll a, ll b)
{
    //cout << a << " && " << b << endl;
    if (c[a][b] != -1) return c[a][b];
    return c[a][b] = C(a-1,b) + C(a-1,b-1);
}

ll solve (ll n, ll p)
{
    if (dp[n][p] != -1) return dp[n][p];
    p = min(n,p);

    //cout << endl << n << " & " << p << endl;

    dp[n][p] = 0;
    for (ll i = 0; i <= p; i++)
    {
        dp[n][p] += C(n,i);

        //cout << "c = " << C(n,i) << endl;
    }
    return dp[n][p];
}

int main()
{
    //freopen ("kimbits.txt","r",stdin);
    freopen ("kimbits.in","r",stdin);
    freopen ("kimbits.out","w",stdout);

    ll n, p, m, i, j, k;

    cin >> n >> p >> m;
    //cout << (1 << 30) << endl;

    /*if (n == p && (m == (1 << (n-1))))
    {
        for (i = 0; i < n; i++)
            cout << '1';
        cout << endl;
        return 0;
    }*/

    memset(c, -1, sizeof (c));
    memset(dp, -1, sizeof (dp));

    for (i = 0; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1;
    }

    for (i = n; i > 0; i--)
    {
        k = solve(i-1,p);

        //cout << endl << k << " " << m << endl;

        if (k >= m) {
            cout << "0";
            continue;
        }
        cout << "1";
        m -= k;
        p--;
    }

    cout << endl;

    return 0;
}


