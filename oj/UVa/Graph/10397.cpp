/*
UVa
graph
10397 - connect the campus
12.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# include <queue>
# include <cmath>
# include <algorithm>

using namespace std;

struct edge {
    int u, v;
    double w;

    bool operator < (const edge &p) const {
        return w < p.w;
    }
};

int X[755], Y[755];
int p [755];
edge e[1000000];

int fup (int a)
{
    if (p[a] == a) return a;
    int ans = fup (p[a]);
    p[a] = ans;
    return ans;
}

int main () {
    int i, n, m, a, b;

    while (cin >> n)
    {
        for (i = 1; i <= n; i++)
            cin >> X[i] >> Y[i];

        cin >> m;
        for (i = 1; i <= n; i++)
            p[i] = i;

        for (i = 0; i < m; i++) {
            cin >> a >> b;

            int pa = fup (a), pb = fup (b);
            if (pa == pb) continue;
            else p[pa] = pb;
        }

        a = 0;
        for (i = 1; i <= n; i++){
            for (b = i+1; b <=n; b++)
            {
                int pa = fup (i), pb = fup (b);
                if (pa == pb) continue;

                e[a].u = i, e[a].v = b;
                e[a].w = (X[i]-X[b])*(X[i]-X[b]) + (Y[i]-Y[b])*(Y[i]-Y[b]);
                e[a].w = sqrt (e[a].w);
                a++;
            }
        }

        sort (e, e+a);
        double cost = 0.0;
        for (i = 0; i < a; i++)
        {
            int pa = fup (e[i].u), pb = fup (e[i].v);
            if (pa == pb) continue;
            p[pa] = pb;
            cost += e[i].w;
        }

        printf ("%.2lf\n", cost);
    }
    return 0;
}
