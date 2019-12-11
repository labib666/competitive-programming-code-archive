# include <cstdio>
# include <iostream>
# include <cstring>

# define inf 100007

using namespace std;

int g [25][25];

void relax (int i, int j, int k)
{
    if (g[i][k] > g[i][j] + g[j][k])
        g[i][k] = g[i][j] + g[j][k];

    return;
}

int main()
{
    int i, j, k, x, y, cnt = 1;
    while (cin >> k){

    for (i=1; i<=20; i++){
        for (j=1;j<=20;j++){
            if (i == j) g[i][j] = 0;
            else g[i][j] = inf;
        }
    }

    for (j=0; j<k; j++)
    {
        cin >> x;
        g[1][x] = 1;
        g[x][1] = 1;
    }

    for (i=2; i<=19; i++)
    {
        cin >> k;
        for (j=0; j<k; j++)
        {
            cin >> x;
            g[i][x] = 1;
            g[x][i] = 1;
        }
    }
    for (y=1;y<=20;y++)
        for (i=1;i<=20;i++)
            for (j=1;j<=20;j++)
                for (x=1;x<=20;x++)
                    relax (i,j,x);

    cin >> k;

    cout << "Test Set #" << cnt++ << endl;
    while (k--)
    {
        cin >> x >> y;
        printf ("%2d to %2d: %d\n", x, y, g[x][y]);
    }
    cout << endl;
    }
    return 0;
}
