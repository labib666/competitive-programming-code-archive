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

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

int n, k;
//int c[300005];
PII j[300005];
int v[300005];
priority_queue < int > q;

void bs (int a)
{
    int hi, lo, mid;
    hi = n-1, lo = 0;

    while (hi >= lo)
    {
        mid = (hi+lo)/2;
        if (j[mid].x <= a)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    v[lo]++;

    return;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int i, p;

    scanf ("%d%d", &n, &k);
    fill (v, v+n+1, 0);

    for (i = 0; i < n; i++)
    {
        scanf ("%d%d", &j[i].x, &j[i].y);
    }

    sort (j, j+n);
    j[n] = make_pair(0,0);

    for (i = 0; i < k; i++)
    {
        scanf ("%d", &p);
        bs (p);
    }

    ll ans = 0;

    for (i = 0; i <= n; i++)
    {
        if (v[i])
        {
            for (p = 0; p < v[i]; p++)
            {
                if (q.empty()) break;
                ans += q.top();
                q.pop();
            }
        }

        q.push(j[i].y);
    }

    cout << ans << endl;


    return 0;
}
