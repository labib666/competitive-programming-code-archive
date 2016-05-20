/*
USACO
bitmask, NT
2.1.2 - frac1
16.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: frac1
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>

using namespace std;

struct frac {
    int a, b;
    double f;

    bool operator < (const frac &p) const {
        return f > p.f;
    }
};

int dp [165][6];
priority_queue <frac> q;

void sieve ()
{
    int p[165], i, j, k;
    memset(dp, 0, sizeof (dp));
    memset(p, 0, sizeof (p));

    for (i = 2; i < 161; i++)
    {
        if (p[i]) continue;
        k = (i/32);
        for (j = 1; j <= 160/i; j++)
        {
            p[i*j] = 1;
            dp[i*j][k] |= (1 << (i%32));
        }
    }
    return;
}

bool check (int a, int b)
{
    for (int i = 0; i < 6; i++)
    {
        if (dp[a][i] & dp[b][i])
            return true;
    }
    return false;
}

int main ()
{
    int n, i, j;
    frac f1, f2;
    double x, y;

    freopen ("frac1.in", "r", stdin);
    freopen ("frac1.out", "w", stdout);

    cin >> n;
    sieve();

    f1.a = 0, f1.b = 1, f1.f = 0.0/1.0;
    f2.a = 1, f2.b = 1, f2.f = 1.0/1.0;
    q.push (f1);
    q.push (f2);

    for (i = 1; i <= n; i++)
    {
        for (j = i+1; j <= n; j++)
        {
            if (!check(i, j)){
                f1.a = i, f1.b = j;
                x = i, y = j;
                f1.f = x/y;
                q.push (f1);
            }
        }
    }

    while (!q.empty())
    {
        f1 = q.top();
        q.pop();

        printf ("%d/%d\n", f1.a, f1.b);
    }
    return 0;
}
