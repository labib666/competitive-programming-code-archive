/*
UVa
DP
10130 - SuperSale
6.01.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;

int dp[35];
int w[1001];
int v[1001];
int take[101];

int main()
{
    int t, n, g, i, j, k, x, max, res;
    scanf ("%d", &t);

    for (i=0; i<t; i++)
    {
        memset (dp, -1, sizeof(dp));
        dp[0] = 0;

        scanf ("%d", &n);
        for (j=0; j<n; j++)
            scanf ("%d %d", &v[j], &w[j]);

        scanf ("%d", &g);
        for (j=0; j<g; j++)
            scanf ("%d", &take[j]);
        sort (take, take+g);

        for (j=0; j<n; j++)
        {
            for (k = 30; k>=w[j]; k--)
            {
                if (dp[k - w[j]] != -1)
                {
                    if (dp[k-w[j]] + v[j] > dp[k])
                        dp[k] = dp[k-w[j]] + v[j];
                }
            }
        }

        max = 0;
        res = 0;
        for (j=0,k=0; j<g; j++)
        {
            x = take[j];
            for (; k<=x; k++)
                if (dp[k] > max) max = dp[k];

            res += max;
        }

        printf ("%d\n", res);
    }

    return 0;
}
