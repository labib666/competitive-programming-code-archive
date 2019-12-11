/*
USACO
3.1.3 - Humble numbers
implementation & NT
20.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: humble
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

int main()
{
    //freopen ("humble2.txt","r",stdin);
    freopen ("humble.in","r",stdin);
    freopen ("humble.out","w",stdout);

    ll n, m, i, j, k, z;
    ll cur, c1, c2;
    ll p[100], c[100], h[100005];

    cin >> n >> m;

    for (i = 0; i < n; i++)
        cin >> p[i];
    fill (c,c+n,0);

    h[0] = 1;
    for (i = 0; i < m; i++)
    {
        //cout << i << " && " << h[i] << endl;
        h[i+1] = (1ll << 32);

        for (j = 0; j < n; j++)
        {
            for (k = c[j]; k <= i; k++)
            {
                if (h[k]*p[j] > h[i])
                {
                    c[j] = k;
                    break;
                }
            }

            if (h[k]*p[j] < h[i+1])
                h[i+1] = h[k]*p[j];
        }

        //cout << h[i+1] << " new val \n";
    }

    cout << h[m] << endl;

    return 0;
}

