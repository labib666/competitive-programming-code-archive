/*
UVa
DP - 0-1 knapsack
562 - Dividing Coins
28.1.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

long long int dp[50005];

int main()
{
    int coin [105];
    int t, i, n, j, sum, k, half, res, mx;

    cin >> t;
    for (i=1; i<t+1; i++)
    {
        memset (dp, 0, sizeof(dp));
        sum  =  0;
        dp[0] = 1;

        scanf ("%d", &n);
        for (j=0; j<n; j++)
        {
            scanf ("%d", &coin[j]);
            sum += coin[j];
        }

        half = sum / 2;
        mx = 0;

        for (j=0; j<n; j++)
        {
            for (k = half; k >= coin[j]; k--)
            {
                dp[k] += dp[k - coin[j]];
                if (dp[k] > 0 && mx < k) mx = k;
            }
        }

        res = sum - 2*mx;

        printf ("%d\n", res);
    }

    return 0;
}
