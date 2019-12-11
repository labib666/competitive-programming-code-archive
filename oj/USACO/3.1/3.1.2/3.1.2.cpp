/*
USACO
knapsack dp
3.1.2 - score inflation
6.8.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: inflate
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

int dp[10000], w[10000], v[10000];

int main()
{
    //freopen ("inflate.txt","r",stdin);
    freopen ("inflate.in","r",stdin);
    freopen ("inflate.out","w",stdout);
    int n, t, i, j, k;

    cin >> t >> n;

    for (i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    for (i = 0; i < n; i++)
    {
        for (j = v[i]; j <= t; j++)
        {
            if (dp[j-v[i]] + w[i] > dp[j])
            {
                dp[j] = dp[j-v[i]] + w[i];
            }
        }
    }

    int ans = 0;
    for (i = 0; i <= t; i++)
        ans = max (ans, dp[i]);

    cout << ans << endl;

    return 0;
}

