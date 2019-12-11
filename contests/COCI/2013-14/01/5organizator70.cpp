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

ll n, a[2000005];

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    ll mx = 0, i, j, k;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        a[k]++;
        mx = max(mx, k);
    }

    ll ans = 0;
    for (i = 1; i <= mx; i++)
    {
        ll sum = 0;
        ll cnt = 0;
        for (j = 1; i*j <= mx; j++)
        {
            if (a[i*j]) { sum += i*a[i*j]; cnt += a[i*j]; }
        }
        if (cnt > 1) ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
