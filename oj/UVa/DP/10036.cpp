/*
UVa
dp
10036 -divisibility
9.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

int d [10005];
int dp [10005][105];

int main ()
{
    int t, i, j, n, k, x, d1, d2, div;
    cin >> t;
    while (t--)
    {
        memset (dp, 0, sizeof (dp));
        memset (d, 0, sizeof (d));

        cin >> n >> k;
        for (i = 1; i <= n; i++)
            cin >> d[i];

        for (div = 10000; div < 10000+ k; div++) {
            if (div % k) continue;
            break;
        }

        dp[0][0] = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < k; j++)
            {
                if (dp[i-1][j])
                {
                    d1 = (div + j - d[i])%k, d2 = (div + j + d[i])%k;
                    dp[i][d1] = 1;
                    dp[i][d2] = 1;
                }
            }
        }

        if (dp[n][0] == 1) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
    return 0;
}
