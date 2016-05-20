/*
UVa
11008 - antimatter ray clearcutting
dp, bitmask
23.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp [66000], e[20][20], x[20], y[20], d, n, bc[66000];

int bit (int a)
{
    return (a == 0) ? 0 : 1 + bit (a & (a-1));
}

int solve (int mask)
{
    if (bc[mask] >= d)
         return 0;
    if (dp[mask] != -1)
        return dp[mask];

    int m, ans, i, j, k;
    dp[mask] = 0x33333333;

    for (i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            continue;
        for (j = i+1; j < n; j++)
        {
            m = mask | e[i][j];
            ans = 1 + solve(m);
            dp[mask] = min (ans, dp[mask]);
        }
    }
    return dp[mask];
}

int main()
{
    int t,cnt = 0, i, j, k, ax, ay, bx, by, ans;

    for (i=0; i<(1<<16); i++)
        bc[i] = bit (i);

    cin >> t;
    while (cnt < t)
    {
        cin >> n >> d;
        if (cnt) cout << endl;

        for (i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        if (d == 1 || d == 2){
            printf ( "Case #%d:\n1\n", ++cnt);
            continue;
        }

        memset(dp, -1, sizeof (dp));
        memset(e, 0, sizeof (e));

        for (i = 0; i < n; i ++)
        {
            for (j =0; j <n; j++)
            {
                if (i == j)
                    continue;
                e[i][j] = e[i][j] | (1 << i);
                e[i][j] = e[i][j] | (1 << j);

                ax = x[i] - x[j], ay = y[i] - y[j];
                for (k = 0; k < n; k++)
                {
                    bx = x[j] - x[k], by= y[j] - y[k];
                    if (ax*by == bx*ay)
                        e[i][j] = e[i][j] | (1 << k);
                }
            }
        }

        ans = solve(0);
        printf ( "Case #%d:\n%d\n", ++cnt, ans);
    }

    return 0;
}
