/*
UVa
DP - recursion
10910 - mark distribution
9.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

int dp [71][71], p, ex;

inline int find (int m, int s)
{
    if (s*p > m) return 0;
    if (s == 1) return 1;

    if (dp[m][s] != -1) return dp[m][s];

    int i, ans = 0, res;
    for (i = p; i <= ex; i++)
    {
        res = find (m - i, s - 1);
        if (res == 0) break;

        ans += res;
    }

    dp [m][s] = ans;
    return ans;
}

int main()
{
    int s, m, t, i;

    cin >> t;
    for (i=0; i<t; i++)
    {
        memset (dp, -1, sizeof(dp));

        cin >> s >> m >> p;

        ex = m - p*(s-1);

        int ans = find(m,s);

        cout << ans << endl;
    }

    return 0;
}

