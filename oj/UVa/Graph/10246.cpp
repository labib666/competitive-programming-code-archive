/*
UVa
16.3.2013
10246 - asterix & obelix
graph
*/

# include <cstdio>
# include <cstring>
# include <iostream>

using namespace std;

int d[85][85], c[85][85], f[85];

int main()
{
    int n, r, q, i, j, k, l, dist, cost, cnt = 1;

    while (1)
    {
        cin >> n >> r >> q;
        if (n+r+q == 0) break;
        if (cnt - 1) cout << endl;

        for (i = 1; i <= n; i++)
            cin >> f[i];

        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                if (i == j) d[i][j] = 0, c[i][j] = f[i];
                else d[i][j] = 1000000007, c[i][j] = max (f[i],f[j]);
            }
        }

        for (i = 0; i < r; i++)
        {
            cin >> j >> k >> l;
            d[j][k] = l;
            d[k][j] = l;
        }

        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                for (k = 1; k <= n; k++){
                    dist = d[j][i] + d[i][k];
                    cost = max(c[j][i], c[i][k]);
                    if(d[j][k] + c[j][k] > dist + cost)
                    {
                        d[j][k] = dist;
                        c[j][k] = cost;
                    }
                }
            }
        }
        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                for (k = 1; k <= n; k++){
                    dist = d[j][i] + d[i][k];
                    cost = max(c[j][i], c[i][k]);
                    if(d[j][k] + c[j][k] > dist + cost)
                    {
                        d[j][k] = dist;
                        c[j][k] = cost;
                    }
                }
            }
        }

        cout << "Case #" << cnt++ << endl;
        while (q--)
        {
            cin >> i >> j;
            if (d[i][j] >= 0x33333333)
                cout << "-1" << endl;
            else
                cout << d[i][j] + c[i][j]<< endl;
        }
    }
    return 0;
}
