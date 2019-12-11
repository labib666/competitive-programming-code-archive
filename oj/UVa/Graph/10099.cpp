/*
UVa
10099 - tourist guide
graph
14.3.2013
*/

# include <cstdio>
# include <iostream>
# include <queue>
# include <vector>
# include <cstring>

using namespace std;

struct go {
    int p, c;
    bool operator < (const go &k) const {
        return c < k.c;
    }
};

priority_queue <go> q;
vector <go> e[105];
int cost[105];

int main()
{
    int n, i, j, k, r, s, d, p, cnt = 1;
    go g1, g2;

    while (1) {
        cin >> n >> r;
        if (n + r == 0) break;
        memset(cost, -1, sizeof (cost));

        while (r--)
        {
            cin >> i >> j >> k;

            g1.c = g2.c = k;
            g1.p = j, g2.p = i;

            e[j].push_back (g2);
            e[i].push_back (g1);
        }
        cin >> s >> d >> p;

        g1.p = s, g1.c = 0x33333333;
        q.push (g1);

        while (!q.empty()){
            g1 = q.top();
            q.pop();

            if (cost[g1.p] != -1)
                    continue;
            cost[g1.p] = g1.c;
            if (g1.p == d) break;

            for (i=0; i<(int)e[g1.p].size(); i++) {
                g2 = e[g1.p][i];
                g2.c = min(g2.c,g1.c);
                if (cost[g2.p] != -1) continue;
                q.push (g2);
            }
        }
        int ans;
        if (p%g1.c) ans = p/(g1.c-1) + 1;
        else ans = p/(g1.c-1);

        printf ("Scenario #%d\nMinimum Number of Trips = %d\n\n", cnt++, ans);

        for (i=0; i<=n; i++) e[i].clear();
        while (!q.empty()) q.pop();
    }
    return 0;
}
