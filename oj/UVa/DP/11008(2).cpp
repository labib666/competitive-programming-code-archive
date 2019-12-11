# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp [66000], e[20][20], x[20], y[20], d, n;

int bitcount(int i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int solve (int mask)
{
    if (bitcount(mask) >= d)
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
