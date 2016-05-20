/*
UVa
11553 - grid game
dp, bitmask
15.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int c[10][10], n, N;
int dp[1 << 8][1 << 8];

int solve (int msk1, int msk2) {
    if (msk1 == N && msk2 == N)
        return 0;
    if (dp[msk1][msk2] != 8001)
        return dp [msk1][msk2];

    int i, j, mn, mx = -8001;

    for (i = 0; i < n; i++)
    {
        if (msk1 & (1 << i))
            continue;
        mn = 8001;

        for (j = 0; j < n; j++){
            if (msk2 & (1 << j))
                continue;

            mn = min (mn, c[i][j] + solve (msk1 | (1 << i), msk2 | (1 << j)));
        }

        mx = max (mx, mn);
    }

    dp[msk1][msk2] = mx;
    return mx;
}

int main()
{
    int t, i, j, k;

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cin >> c[i][j];

        N = (1 << n) - 1;
        for (i = 0; i <= N; i++)
            fill (dp[i], dp[i]+ N + 1, 8001);

        cout << solve (0,0) << endl;
    }
    return 0;
}
