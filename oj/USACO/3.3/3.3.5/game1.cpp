/*
USACO
3.3.5 - A Game
DP
7 Feb, 2014
/*
ID: Labib Rashid
LANG: C++
TASK: game1
*/

#include <bits/stdc++.h>
using namespace std;

int dp[105][105], a[105];

int solve (int px, int py, int player)
{
    if (px > py) return 0;
    if (dp[px][py] != -1) return dp[px][py];

    if (player==0) dp[px][py] = max(a[px]+solve(px+1,py,1),a[py]+solve(px,py-1,1));
    if (player==1) dp[px][py] = min(solve(px+1,py,0),solve(px,py-1,0));

    return dp[px][py];
}

int main()
{
    //freopen ("game1.txt","r",stdin);
    freopen ("game1.in","r",stdin);
    freopen ("game1.out","w",stdout);

    int n, i, j, k, ans, sum = 0;

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    memset(dp,-1,sizeof(dp));

    ans = solve(1,n,0);

    cout << ans << " " << sum - ans << endl;

    return 0;
}
