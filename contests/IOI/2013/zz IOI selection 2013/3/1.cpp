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
# define inf 0x33333333

using namespace std;

int dp[2005][2005];
vector <int> s[2005], cost[2005];

int solve (int at, int left, int p, int now, int sz) {
    //cout << at << " " << left << endl;

    if (!left)
        return 0;

    if (now == sz-1 && (int)s[at].size() == 0)
        return (left == 1) ? cost[p][now] : inf;

    if (dp[at][left] != -1)
        return dp[at][left];

    if ((int)s[at].size() == 0){
        dp[at][left] = min (solve(s[p][now+1], left, p, now+1, sz), cost[p][now] + solve(s[p][now+1], left-1, p, now+1, sz));
        return dp[at][left];
    }
    if (now == sz-1)
    {
        dp[at][left] = (left == 1) ? cost[p][now] : cost[p][now] + solve(s[at][0], left-1, at, 0, (int)s[at].size());
        return dp[at][left];
    }

    dp[at][left] = solve(s[p][now+1], left, p, now+1, sz);
    int a1, a2 = cost[p][now];
    for (int i = 0; i <= left-1; i++)
    {
        a1  = solve(s[p][now+1], i, p, now+1, sz) + solve(s[at][0], left-i-1, at, 0, (int)s[at].size());
        dp[at][left] = min (dp[at][left], a1+a2);
    }

    return dp[at][left];
}

int main()
{
    int n, k, i, p;
    int cst;

    cin >> n >> k;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        cin >> p >> cst;
        s[p].pb(i+1);
        cost[p].pb(cst);
    }

    memset(dp, -1, sizeof (dp));

    int ans = solve(s[1][0],k-1,1,0, (int)s[1].size());

    cout << ans << endl;

    return 0;
}
