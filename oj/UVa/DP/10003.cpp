/*
UVa
classic DP
10003 - cutticg sticks
4.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

int c[55], dp[55][55];

int mincost (int a, int b)
{
    if (a == b) return 0;
    if (dp[a][b] != -1)
        return dp[a][b];

    int i, ans = 1000000007, cost;
    for (i=a; i<b; i++)
    {
        cost = mincost(a,i) + mincost(i+1,b);
        if (ans > cost) ans = cost;
    }
    for (i=a; i<=b; i++) ans += c[i];

    dp[a][b] = ans;
    return ans;
}

int main()
{
    int n, m, x, y, prev, i;
    while (1){
        cin >> n;
        if (n == 0) break;

        cin >> m;
        fill (c, c+55, 0);
        memset(dp, -1, sizeof (dp));
        prev = 0,y = 1;

        while (y <= m)
        {
            cin >> x;
            c[y-1] = x - prev;
            prev = x;
            y++;
        }
        c[m] = n - prev;

        int ans = mincost(0,m);

        cout << "The minimum cutting is " << ans << "." << endl;
    }

    return 0;
}
