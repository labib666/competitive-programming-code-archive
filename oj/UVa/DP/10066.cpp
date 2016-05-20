/*
UVa
DP - LCS
10066 - The Twin Tower
2.2.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int n1 [105], n2 [105];
int dp [105][105];
int k1, k2;

inline int lcs (int a, int b)
{
    if (a == k1 || b == k2) return 0;

    if (dp [a][b] != -1) return dp[a][b];

    int a1, a2, ans;

    if (n1[a] == n2[b])
    {
        ans = lcs (a+1,b+1);
        dp[a][b] = ans + 1;
        return ans + 1;
    }

    a1 = lcs (a+1, b);
    a2 = lcs (a, b+1);

    ans = max (a1,a2);
    dp[a][b] = ans;
    return ans;
}

int main()
{
    int res, c=0;
    while (1)
    {
        c++;
        memset (dp, -1, sizeof(dp));

        cin >> k1 >> k2;
        if (k1 == 0 && k2 == 0) break;

        for (int i = 0; i<k1; i++) cin >> n1[i];
        for (int i = 0; i<k2; i++) cin >> n2[i];

        res = lcs (0,0);

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", c, res);
    }

    return 0;
}
