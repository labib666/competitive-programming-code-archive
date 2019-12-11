/*
UVa
DP - LCS
10192 - vacations
5.3.2013
*/

# include <iostream>
# include <cstring>
# include <cstdio>
# include <algorithm>
# include <string>

using namespace std;

char s1[105], s2[105];
int k1, k2, dp[105][105];

int mcost (int a, int b)
{
    if (a == k1 || b == k2)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    int ans, a1, a2;

    if (s1[a] == s2[b])
    {
        ans = mcost(a+1, b+1) + 1;
        dp[a][b] = ans;
        return ans;
    }

    a1 = mcost(a+1, b);
    a2 = mcost(a, b+1);

    ans = max (a1,a2);

    dp[a][b] = ans;
    return dp[a][b];
}

int main()
{
    int cnt = 1;
    while (1)
    {
        gets (s1);
        if (s1[0] == '#') break;
        gets(s2);

        k1 = strlen(s1), k2 = strlen(s2);
        memset(dp, -1, sizeof (dp));

        int ans = mcost(0,0);

        printf ("Case #%d: you can visit at most %d cities.\n", cnt++, ans);
    }

    return 0;
}
