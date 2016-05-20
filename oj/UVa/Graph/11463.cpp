/*
UVa
11463 - commandoes
graph
16.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <queue>

using namespace std;

struct two {
    int p, c;
};

queue <two> q;
vector <int> e[1005];
int d1[1005], d2[1005];

int main()
{
    int n, r, i, j, k, t, st, dst;
    two t1, t2;

    cin >> t;
    for (i = 1; i <= t; i++){
        cin >> n >> r;
        memset(d1, -1, sizeof(d1));
        memset(d2, -1, sizeof(d2));

        while (r--)
        {
            cin >> j >> k;
            e[j].push_back (k);
            e[k].push_back (j);
        }
        cin >> st >> dst;

        t1.p = st, t1.c = 0;
        q.push(t1);

        while (!q.empty())
        {
            t1 = q.front();
            q.pop();

            if (d1[t1.p] != -1) continue;
            d1[t1.p] = t1.c;

            for (j = 0; j < (int)e[t1.p].size(); j++)
            {
                t2.p = e[t1.p][j], t2.c = t1.c + 1;
                if (d1[t2.p] != -1) continue;
                q.push (t2);
            }
        }

        t1.p = dst, t1.c = 0;
        q.push(t1);

        while (!q.empty())
        {
            t1 = q.front();
            q.pop();

            if (d2[t1.p] != -1) continue;
            d2[t1.p] = t1.c;

            for (j = 0; j < (int)e[t1.p].size(); j++)
            {
                t2.p = e[t1.p][j], t2.c = t1.c + 1;
                if (d2[t2.p] != -1) continue;
                q.push (t2);
            }
        }

        int mx = -1;
        for (j = 0; j < n; j++)
            mx = max (mx, d1[j]+d2[j]);

        printf ("Case %d: %d\n", i, mx);

        for (j = 0; j < n; j++)
            e[j].clear();
    }
    return 0;
}
