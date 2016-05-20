/*
UVa
10617 - again palindrome
dp
21.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

long long dp[65][65];
char s[65];

long long solve (int a, int b)
{
    if (a == b)
        return 1;
    if (a > b)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    long long a1, a2, c;
    a1 = solve(a+1, b);
    a2 = solve(a, b-1);
    c = solve(a+1,b-1);

    dp[a][b] = a1 + a2 - c;
    if (s[a] == s[b])
        dp[a][b] += c+1;

    return dp[a][b];
}

int main()
{
    int t, len;

    cin >> t;
    while (t--)
    {
        cin >> s;
        len = (int) strlen (s);
        memset(dp, -1, sizeof (dp));

        cout << solve(0, len-1) << endl;
    }
    return 0;
}
