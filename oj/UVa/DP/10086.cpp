# include <iostream>
# include <cstring>
# include <cstdio>
# include <vector>
# define inf 0x33333333

using namespace std;

int dp[35][305][305], s1[35][25], s2[35][25], m[35];
int n, mem [35][305][305];

int solve (int a, int p1, int p2)
{
    if (a == 0) return 0;

    if (dp[a][p1][p2] != -1)
        return dp[a][p1][p2];

    int ans = inf, a1, i;

    for (i = 0; i <= m[a]; i++)
    {
        if (i > p1 || m[a] - i > p2) continue;
        a1 = s1[a][i] + s2[a][m[a] - i] + solve (a-1, p1-i, p2-m[a]+i);
        if (a1 < ans) {
                ans = a1;
                mem [a][p1][p2] = i;
        }
    }

    dp[a][p1][p2] = ans;
    return ans;
}

void pseq (int a, int p1, int p2)
{
    if (a == 0) return;

    int k = mem[a][p1][p2];

    pseq (a-1, p1 - k, p2 - m[a] + k);

    if (n - a) cout << k << " ";
    else cout << k << endl;
}

int main()
{
    int t1, t2, i, j, a, k;

    while (1)
    {
        cin >> t1 >> t2;
        if (t1 + t2 == 0) break;

        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> j;
            s1[i][0] = s2[i][0] = 0;
            for (k = 1; k <= j; k++)
                cin >> s1[i][k];
            for (k = 1; k <= j; k++)
                cin >> s2[i][k];
            m[i] = j;
        }

        memset (dp, -1, sizeof (dp));
        int ans = solve (n, t1, t2);

        printf ("%d\n", ans);
        pseq (n, t1, t2);
        cout << endl;
    }

    return 0;
}
