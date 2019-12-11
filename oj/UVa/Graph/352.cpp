/*
UVa
352 - seasonal wars
graph
6.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <string>

using namespace std;

string g[27];
int v[27][27], n;
int X[] = {1,1,1,-1,-1,-1,0,0};
int Y[] = {0,-1,1,1,0,-1,1,-1};

void flow (int a, int b)
{
    int i, xi, yi;
    v[a][b] = 1;
    g[a][b] = '0';

    for (i=0;i<8;i++)
    {
        xi = a + X[i];
        yi = b + Y[i];
        if (xi > n - 1|| xi < 0 || yi > n - 1 || yi < 0) continue;
        if (v[xi][yi]) continue;

        if (g[xi][yi] == '1') flow(xi, yi);
    }
    return;
}

int main()
{
    int i, j, cnt = 1, ans;
    //freopen("e.txt", "r" , stdin);
    //freopen("e.txt", "w", stdout);
    while (scanf ("%d", &n) != EOF)
    {
        memset (v, 0, sizeof (v));

        for (i = 0; i < n; i++)
            cin >> g[i];

        ans = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (v[i][j]) continue;
                if (g[i][j] == '1') {
                    ans++;
                    flow (i,j);
                }
            }
        }

        printf ("Image number %d contains %d war eagles.\n", cnt++, ans);
    }
    return 0;
}
