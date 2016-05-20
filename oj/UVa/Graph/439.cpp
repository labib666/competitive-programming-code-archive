/*
UVa
DP
439 - knight moves
5.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <sstream>
# include <queue>

using namespace std;

struct go {
    int px, py, mc;
};

int main()
{
    int i, j, x, y, dx, dy, c;
    char s1[5], s2[5];
    int v[9][9];
    queue <go> q;
    go m, n;
    int X[] = {1,1,-1,-1,2,2,-2,-2};
    int Y[] = {2,-2,-2,2,1,-1,-1,1};

    while (cin >> s1 >> s2)
    {
        while (!q.empty()) q.pop();
        memset (v,0, sizeof(v));

        stringstream ss1;
        ss1 << s1[1];

        m.px = s1[0] - 'a' + 1;
        ss1 >> m.py;
        m.mc = 0;

        stringstream ss2;
        ss2 << s2[1];

        dx = s2[0] - 'a' + 1;
        ss2 >> dy;

        q.push (m);

        while (!q.empty())
        {
            m = q.front();
            q.pop();

            x = m.px;
            y = m.py;
            c = m.mc;

            if (v[x][y]) continue;
            //cout << "visiting >> " << x << " " << y << " " << c << endl;
            if (x == dx && y == dy) break;

            v[x][y] = 1;
            int xi, yi;
            for (i = 0; i<8; i++)
            {
                xi = x + X[i];
                yi = y + Y[i];

                if (xi < 1 || xi > 8) continue;
                if (yi < 1 || yi > 8) continue;
                if (v[xi][yi]) continue;

                n.mc = c+1;
                n.px = xi;
                n.py = yi;

                q.push(n);
            }
        }

        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, c);
    }
    return 0;
}
