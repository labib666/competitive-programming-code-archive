/*
USACO
dp
2.3.4 - Money Systems
21.4.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: money
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

using namespace std;

ll dp[10005], a[32];

int main()
{
    freopen ("money.in","r",stdin);
    freopen ("money.out","w",stdout);

    ll n, w, i, j, k;
    cin >> w >> n;

    for (i = 0; i < w; i++)
        cin >> a[i];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (i = 0; i < w; i++)
    {
        k = a[i];
        for (j = k; j <= n; j++)
        {
            dp[j] += dp[j-k];
        }
    }

    cout << dp[n] << endl;

    return 0;
}

