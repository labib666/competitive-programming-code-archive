# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;
struct edge {
    int u, v, w;
};

int d[85][85], c[85][85], f[85];
edge e[10000];

int main()
{
    int n, r, q, i, j, k, u, v, w, cnt = 0;

    while (1)
    {
        cin >> n >> r >> q;
        if (n + q + r == 0) break;
        if (cnt) break;

        for (i = 1; i <= n; i++)
            cin >> f[i];

        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++)
            {
                if (i == j) d[i][j] = 0, c[i][j] = f[i];
                else d[i][j] = 0x33333333, c[i][j] = max (f[i],f[j]);
            }
        }

        for (i = 0; i < r; i++)
            cin >> e[i].u >> e[i].v >> e[i].w;

        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                for (k = 0; k < r; k++) {
                    u = e[k].u, v = e[k].v, w = e[k].w;

                    if (d[i][v] + c[i][v] > d[i][u] + w + max (c[i][u],c[u][v]))
                        d[i][v] = d[i][u] + w, c[i][v] = max (c[i][u],c[u][v]);
                    if (d[i][u] + c[i][u] > d[i][v] + w + max (c[i][v],c[v][u]))
                        d[i][u] = d[i][v] + w, c[i][u] = max (c[i][v],c[v][u]);
                }
            }
        }
        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                for (k = 0; k < r; k++) {
                    u = e[k].u, v = e[k].v, w = e[k].w;

                    if (d[i][v] + c[i][v] > d[i][u] + w + max (c[i][u],c[u][v]))
                        d[i][v] = d[v][i] = min (d[v][i],d[i][u] + w), c[i][v] = max (c[i][u],c[u][v]);
                    if (d[i][u] + c[i][u] > d[i][v] + w + max (c[i][v],c[v][u]))
                        d[i][u] = d[u][i] = min (d[u][i],d[i][v] + w), c[i][u] = max (c[i][v],c[v][u]);
                }
            }
        }

        while (q--)
        {
            cin >> i >> j;
            if (d[i][j] == 0x33333333)
                cout << "-1\n";
            else
                cout << d[i][j] + c[i][j] << endl;
        }
    }
    return 0;
}
