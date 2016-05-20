# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define inf 1000000007

using namespace std;

int dp[256][32], d[256], sum[256], s[256][32], n, k;

inline int place (int a, int b)
{
    int i,c1,cost = inf, p = a, j;
    for (i=a; i <= b; i++)
    {
        c1 = (2*i - a - b-1)*d[i] - 2*sum[i] + sum[a] + sum[b+1];
        if (c1 < cost) {
                cost = c1;
                p = i;
        }
    }
    return p;
}

inline int findc (int a, int b)
{
    int i, j, cost = inf, c1;

    for (i = a; i <= b; i++)
    {
        c1 = (2*i - a - b-1)*d[i] - 2*sum[i] + sum[a] + sum[b+1];
        if (c1 < cost) cost = c1;
    }
    return cost;
}

inline int mcost (int a, int rem)
{
    if (rem == 0)
        return (a == 0) ? 0 : inf;

    if (dp[a][rem] != -1) return dp[a][rem];

    int i, cost = inf, p = 0, c1, c2;
    for (i = rem; i <= a; i++)
    {
        c1 = mcost (i-1,rem-1);
        c2 = findc (i, a);

        if (cost > c1 + c2) {
                cost = c1 + c2;
                p = i;
        }
    }

    dp[a][rem] = cost;
    s[a][rem] = p;

    return cost;
}

inline void pseq (int a, int rem)
{
    if (rem != 1)pseq(s[a][rem]-1,rem-1);
    if (a - s[a][rem])
        printf ("Depot %d at restaurant %d serves restaurants %d to %d\n", rem, place(s[a][rem], a), s[a][rem], a);
    else
        printf ("Depot %d at restaurant %d serves restaurant %d\n", rem, a, a);
    return;
}

int main ()
{
    int i, j, cnt = 1;

    while (1)
    {
        cin >> n >> k;
        if (n+k == 0) break;

        memset(dp, -1, sizeof (dp));
        memset (s, -1, sizeof (s));

        for (i=1,sum[1]=0; i<=n; i++){
            cin >> d[i];
            sum[i+1] = sum[i]+d[i];
        }

        int ans = mcost (n, k);

        cout << "Chain " << cnt++ << endl;
        pseq (n,k);
        printf ("Total distance sum = %d\n\n", ans);
    }
    return 0;
}
