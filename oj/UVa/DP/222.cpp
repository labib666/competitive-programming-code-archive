/*
UVa
DP
222 - budget travels
10.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <queue>
# include <cmath>
# define inf 1000000000000000007.0

using namespace std;
struct state {
    double cost, oil;
};

state s[55][55];

int main()
{
    double x, sz, mil;
    double d[55], c[55], cost1, cost2;
    int n, i, j, cnt = 1;

    while (1)
    {
        cin >> x;
        if (x < 0) break;

        d[0] = 0.0;
        cin >> sz >> mil >> cost1 >> n;
        d[n+1] = x;

        for (i=1; i<= n; i++)
            cin >> d[i] >> c[i];

        for (i = 0; i <= n+1; i++)
            for (j = 0; j <= n+1; j++)
                s[i][j].cost = inf;

        s[0][0].cost = cost1*100, s[0][0].oil = sz;

        for (i = 0; i <= n; i++)
        {
            for (j = i; j <=n; j++)
            {
                state s1, s2;
                s1.cost = s[i][j].cost;
                s1.oil = s[i][j].oil - (d[j+1]-d[j])/mil;
                if (s1.oil >= 0 && s1.cost < s[i][j+1].cost)
                    s[i][j+1] = s1;

                if (i == j) continue;

                if (s[i][j].oil < sz/2 || s1.oil < 0){
                    s2.oil = sz;
                    cost1 = floor((sz - s[i][j].oil)*c[j]);
                    if ((sz - s[i][j].oil)*c[j] - cost1 >= .5) cost1++;
                    s2.cost = s[i][j].cost + cost1 + 200.0;
                    if (s2.cost < s[j][j].cost)
                        s[j][j] = s2;
                }
            }
        }

        double ans = inf;
        for (i = 0; i <= n; i++)
            ans = min (ans, s[i][n+1].cost);
        ans /= 100.0;

        printf ("Data Set #%d\nminimum cost = $%.2lf\n", cnt++, ans);
    }
    return 0;
}
