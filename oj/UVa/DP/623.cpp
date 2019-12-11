/*
UVa
DP - big int
623 - 500!
8.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp [1001][2751];

int main()
{
    int n, i, j, c, sum;
    memset (dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (i = 1; i < 1001; i++)
    {
        c = 0;
        for (j = 0; j < 2751; j++)
        {
            sum = dp[i-1][j] * i + c;

            dp[i][j] = sum % 10;
            c = sum / 10;
        }
    }

    while (cin >> n)
    {
        cout << n << "!\n";
        j = 0;
        for (i = 2750; i >= 0; i--)
        {
            if (j == 0 && dp[n][i] > 0) j = 1;
            if (j == 1) cout << dp[n][i];
        }
        cout << endl;
    }

    return 0;
}
