/*
Dancing cows
http://cerberus.delos.com:790/trainprobs2?p=1090&a=U7hm3fua8rP
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
# define inf 1000000007

using namespace std;

ll dp[501][501], ch[501], bh[501];

ll solve (int at, int left) {

    if (!left)
        return 0;
    if (at < left)
        return inf;
    if (dp[at][left] != -1)
        return dp[at][left];

    ll a1, a2;
    a1 = solve(at-1, left-1) + abs (ch[at] - bh[left]);
    a2 = solve(at-1, left);

    dp[at][left] = min (a1, a2);

    return dp[at][left];
}

int main()
{
    int n, m, i, j, k;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
        cin >> bh[i];
    for (i = 1; i <= m; i++)
        cin >> ch[i];

    sort (bh+1, bh+n+1);
    sort (ch+1, ch+m+1);

    memset(dp, -1, sizeof (dp));

    ll ans = solve(m,n);

    cout << ans << endl;

    return 0;
}
