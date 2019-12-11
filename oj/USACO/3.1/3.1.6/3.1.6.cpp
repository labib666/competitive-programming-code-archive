/*
USACO
3.1.6 - Stamps
DP - coin change
20.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: stamps
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

int c[50];
bool v[2000005];
int dp[2000005];

int main()
{
    //freopen ("stamps.txt","r",stdin);
    freopen ("stamps.in","r",stdin);
    freopen ("stamps.out","w",stdout);

    int i, j, k, n, m;

    cin >> m >> n;

    for (i = 0; i < n; i++)
        cin >> c[i];

    sort (c,c+n);
    for (i = 1; i <= c[n-1]*m; i++)
        dp[i] = inf;
    v[0] = 1, dp[0] = 0;

    for (j = 0; j <= m*c[n-1]; j++)
    {
        if (!v[j]) break;
        if (dp[j] == m) continue;

        for (i = n-1; i >= 0; i--)
        {
                v[j + c[i]] = 1;
                dp[j + c[i]] = min (dp[j + c[i]], dp[j] + 1);
        }
    }

    //for (i = 1; i <= m*c[n-1]; i++)
      //  if (v[i]) cout << i << endl;

    cout << j-1 << endl;

    return 0;
}

