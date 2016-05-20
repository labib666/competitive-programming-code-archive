/*
UVa
DP - LIS
10131 - Is bigger smarter
6.2.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# define inf 1000000007

using namespace std;

struct el{
    int w, s, t;
    bool operator < (const el &p) const{
        return s > p.s;
    }
};

el n [1005];
int p, dp [1005];

inline void findseq (int mx)
{
    int i;
    el v;
    v.s = inf, v.w = (-1)*inf;

    for (i = 0; i < p; i++)
    {
        if (mx == dp[i] && v.s > n[i].s && v.w < n[i].w)
        {
            mx -- ;
            v.s = n[i].s, v.w = n[i].w;
            cout << n[i].t << endl;

            if (mx == 0) break;
        }
    }

    return;
}

int main()
{
    int x, y, i, res, j;

    p = 0;
    while (scanf("%d %d", &x, &y) != EOF)
    {
        n[p].w = x, n[p].s = y, n[p].t = p+1;
        p++;
    }

    sort (n, n+p);

    res = 0;
    for (i = p-1; i >= 0; i--)
    {
        dp[i] = 1;

        for (j = i+1; j < p; j++)
        {
            if (n[j].s < n[i].s && n[j].w > n[i].w && dp[i] < 1 + dp[j])
                dp[i] = 1 + dp[j];
        }

        if (dp[i] > res) res = dp[i];
    }

    cout << res << endl;
    findseq (res);

    return 0;
}
