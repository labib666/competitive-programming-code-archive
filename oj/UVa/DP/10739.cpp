/*
UVa
dp
10739 - string palindrome
20.3.2013
*/

# include <cstdio>
# include <cstring>
# include <string>
# include <iostream>

using namespace std;

char s1[1005];
int dp[1005][1005];

int solve(int a, int b)
{
    if (a >= b)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    if (s1[a] == s1[b])
    {
        dp[a][b] = solve(a+1, b-1);
        return dp[a][b];
    }

    dp[a][b] = 1 + min (solve(a+1,b-1), min(solve(a+1,b), solve(a, b-1)));
    return dp[a][b];
}

int main ()
{
    int t, i, j, k, cnt = 1, sz;

    cin >> t;
    while (cnt <= t)
    {
        cin >> s1;
        sz = (int)strlen(s1);
        memset(dp, -1, sizeof (dp));

        printf ("Case %d: %d\n", cnt++, solve(0,sz-1));
    }
    return 0;
}
