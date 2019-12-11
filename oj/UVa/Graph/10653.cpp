/*
UVa
10653 - Bombs! NO they are Mines!!
graph
7.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>

using namespace std;
struct go {
    int px, py, c;
};

int g[1005][1005], v[1005][1005];
int X[] = {1,-1,0,0};
int Y[] = {0,0,1,-1};
queue <go> q;

int main()
{
    int r, c, i, j, k, m, dx, dy;
    go g1, g2;

    while (1)
    {
        cin >> r >> c;
        if (r + c == 0) break;
        memset(g, 0, sizeof(g));
        memset(v, 0, sizeof(v));

        cin >> i;
        while (i--)
        {
            cin >> j >> k;
            while (k--)
            {
                cin >> m;
                g[j][m] = 1;
            }
        }
        cin >> g1.px >> g1.py;
        g1.c = 0;
        q.push(g1);

        cin >> dx >> dy;

        while (!q.empty())
        {
            g1 = q.front();
            q.pop();

            i = g1.px, j = g1.py, k = g1.c;
            if (v[i][j]) continue;
            if (i == dx && j == dy) break;

            v[i][j] = 1;
            for (m=0;m<4; m++)
            {
                g2.px = i + X[m];
                g2.py = j + Y[m];
                g2.c = k + 1;

                if (g2.px < 0 || g2.px >= r) continue;
                if (g2.py < 0 || g2.py >= c) continue;

                if (v[g2.px][g2.py]) continue;
                if (g[g2.px][g2.py]) continue;

                q.push(g2);
            }
        }
        cout << k << endl;
        while (!q.empty()) q.pop();
    }
    return 0;
}

