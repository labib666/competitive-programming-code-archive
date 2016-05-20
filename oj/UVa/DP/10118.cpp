/*
UVa
10118 - free candies
dp
23.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;

int dp[42][42][42][42], s[4][42], n;

int solve (int a, int b, int c, int d, int cnt, int bit)
{
    if (cnt == 5)
        return 0;
    if (a+b+c+d == 0)
        return 0;
    if (dp[a][b][c][d] != -1)
        return dp[a][b][c][d];

    int bit1, i, ans, U, cn2;
    dp[a][b][c][d] = 0;
    if (a != 0) {
        U = a-1, i = s[0][n-a];
        cn2 = cnt + 1;
        if ((bit >> i) & 1){
            cn2 = cn2 - 2;
            bit1 = bit;
            bit1 = bit1 & (~(1 << i));
            ans = 1 + solve (U,b,c,d,cn2,bit1);
        }
        else {
            bit1 = bit | (1 << i);
            ans = solve (U,b,c,d,cn2,bit1);
        }
        dp[a][b][c][d] = max (ans, dp[a][b][c][d]);
    }
    if (b != 0) {
        U = b-1, i = s[1][n-b];
        cn2 = cnt + 1;
        if ((bit >> i) & 1){
            cn2 = cn2 - 2;
            bit1 = bit;
            bit1 = bit1 & (~(1 << i));
            ans = 1 + solve (a,U,c,d,cn2,bit1);
        }
        else {
            bit1 = bit | (1 << i);
            ans = solve (a,U,c,d,cn2,bit1);
        }
        dp[a][b][c][d] = max (ans, dp[a][b][c][d]);
    }
    if (c != 0) {
        U = c-1, i = s[2][n-c];
        cn2 = cnt + 1;
        if ((bit >> i) & 1){
            cn2 = cn2 - 2;
            bit1 = bit;
            bit1 = bit1 & (~(1 << i));
            ans = 1 + solve (a,b,U,d,cn2,bit1);
        }
        else {
            bit1 = bit | (1 << i);
            ans = solve (a,b,U,d,cn2,bit1);
        }
        dp[a][b][c][d] = max (ans, dp[a][b][c][d]);
    }
    if (d != 0) {
        U = d-1, i = s[3][n-d];
        cn2 = cnt + 1;
        if ((bit >> i) & 1){
            cn2 = cn2 - 2;
            bit1 = bit;
            bit1 = bit1 & (~(1 << i));
            ans = 1 + solve (a,b,c,U,cn2,bit1);
        }
        else {
            bit1 = bit | (1 << i);
            ans = solve (a,b,c,U,cn2,bit1);
        }
        dp[a][b][c][d] = max (ans, dp[a][b][c][d]);
    }
    return dp[a][b][c][d];
}

int main ()
{
    int i, j, k, ans, bit;
    while (1)
    {
        cin >> n;
        if (!n) break;

        for (i = 0; i < n; i++)
            cin >> s[0][i] >> s[1][i] >> s[2][i] >> s[3][i];

        memset (dp, -1, sizeof (dp));

        ans = solve(n,n,n,n,0,0);

        cout << ans << endl;
    }
    return 0;
}
