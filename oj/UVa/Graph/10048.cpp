/*
UVa
10048 - audophobia
graph
15.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

struct edge {
    int u, v, w;
};

int d[105][105];
edge e[1005];

int main()
{
    int n, r, q, i, j, k, cnt = 1;;
    while (1)
    {
        cin >> n >> r >> q;
        if (n+r+q == 0) break;
        if (cnt-1) cout << endl;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                d[i][j] = 0x33333333;
        for (i = 1; i <=n; i++)
            d[i][i] = 0;

        for (i = 0; i < r; i++)
            cin >> e[i].u >> e[i].v >> e[i].w;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                for (k = 0; k <r; k++){
                    d[i][e[k].v] = min (d[i][e[k].v], max (d[i][e[k].u],e[k].w));
                    d[i][e[k].u] = min (d[i][e[k].u], max (d[i][e[k].v],e[k].w));
                }

        cout << "Case #" << cnt++ << endl;
        while (q--)
        {
            cin >> i >> j;
            if (d[i][j] != 0x33333333)
                cout << d[i][j] << endl;
            else
                cout << "no path\n";
        }
    }
}
