/*
UVa
grph - mst - kruskal
10034 - freckles
11.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <queue>
# include <cmath>
# include <algorithm>

using namespace std;

struct edge {
    int u, v;
    double w;
    bool operator < (const edge &p) const{
        return w < p.w;
    }
};

int p [105];

int fup (int a){
    if (a == p[a]) return a;
    int ans = fup (p[a]);
    p[a] = ans;
    return ans;
}

int main ()
{
    int t, i, j, n, m;
    double a, b, c, X[105], Y[105];
    edge e[10010];

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >>  X[i] >> Y[i];

        m = 0;
        for (i = 0; i < n; i++){
            for (j = i+1; j < n; j++) {
                e[m].u = i, e[m].v = j;
                e[m].w = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
                e[m].w = sqrt(e[m].w);
                m++;
            }
        }

        sort (e, e+m);
        for (i = 0; i < n; i++) p[i] = i;

        int pa, pb;
        double cost = 0.0;
        for (i = 0; i < m; i++) {
            pa = fup (e[i].u), pb = fup (e[i].v);
            if (pa == pb) continue;

            p[pa] = pb;
            cost += e[i].w;
        }
        printf ("%.2lf\n", cost);

        if (t) cout << endl;
    }

    return 0;
}

