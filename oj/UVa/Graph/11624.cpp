/*
UVa
11624 - Fire
graph
16.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <queue>

using namespace std;

struct go {
    int px, py, pc;
};

string g[1005];
int v[1005][1005], f[1005][1005];
int X[] = {1,-1,0,0};
int Y[] = {0,0,-1,1};
queue <go> q;

int main ()
{
    int c, r, i, j, k, t, sx, sy;
    go g1, g2, g3;

    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        for (i = 0; i < r; i++) {
            cin >> g[i];
            for (j = 0; j < c; j++){
                if (g[i][j] == 'F'){
                    g2.px = i, g2.py = j;
                    g2.pc = 0;
                    q.push(g2);
                }
                if (g[i][j] == 'J'){
                    sx = i, sy = j;
                }
            }
        }

        memset(v, 0, sizeof (v));
        memset(f, -1, sizeof (f));
        int success = 0;

        while (!q.empty()) {
            g1 = q.front();
            q.pop();

            if (f[g1.px][g1.py] != -1 && f[g1.px][g1.py] <= g1.pc) continue;
            f[g1.px][g1.py] = g1.pc;

            for (i=0; i<4; i++){
                g3.px = g1.px + X[i], g3.py = g1.py + Y[i];
                g3.pc = g1.pc + 1;
                if (g3.px < 0 || g3.px >= r || g3.py < 0|| g3.py >= c)
                    continue;
                if (f[g3.px][g3.py] != -1 && f[g3.px][g3.py] <= g3.pc)
                    continue;
                if (g[g3.px][g3.py] == '#') continue;

                q.push (g3);
            }
        }

        g1.px = sx, g1.py = sy, g1.pc = 0;
        q.push (g1);

        while (!q.empty()) {
            g1 = q.front();
            q.pop();

            if (g1.px < 0 || g1.px >= r || g1.py < 0|| g1.py >= c){
                success = 1;
                break;
            }

            if (v[g1.px][g1.py]) continue;
            v[g1.px][g1.py] = 1;

            for (i=0; i<4; i++){
                g3.px = g1.px + X[i], g3.py = g1.py + Y[i];
                g3.pc = g1.pc + 1;
                if (g3.px < 0 || g3.px >= r || g3.py < 0|| g3.py >= c){
                    q.push (g3);
                    continue;
                }
                if (v[g3.px][g3.py])
                    continue;
                if (f[g3.px][g3.py] != -1 && f[g3.px][g3.py] <= g3.pc)
                    continue;
                if (g[g3.px][g3.py] == '#') continue;

                q.push (g3);
            }
        }

        while (!q.empty()) q.pop();

        if (success) cout << g1.pc << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
