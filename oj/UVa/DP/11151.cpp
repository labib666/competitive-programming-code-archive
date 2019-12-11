/*
UVa
dp
11151 - longest palindrome
20.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp[1005][1005], len;
char s[1005];

int solve(int a, int b)
{
    if (a == b)
        return 1;
    if (a > b)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    int a1, a2;
    if (s[a] == s[b])
    {
        dp[a][b] = 2 + solve(a+1, b-1);
        return dp[a][b];
    }

    a1 = solve(a+1, b);
    a2 = solve(a, b-1);

    dp[a][b] = max (a1,a2);

    return dp[a][b];
}

int main()
{
    int t, i, j;
    cin >> t;
    gets (s);

    while (t--)
    {
        gets (s);
        len = (int) strlen (s);

        memset(dp, -1, sizeof (dp));
        int ans = solve(0,len-1);

        cout << ans << endl;
    }
    return 0;
}
