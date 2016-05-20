/*
UVa
graph - bfs
571 - jugs
9.3.2013
*/

# include <iostream>
# include <cstdio>
# include <queue>
# include <cstring>

using namespace std;

struct two {
    int px, py, c, x, y;
};

int m[3], c[3];
queue <two> q;
int v[1005][1005], p[1005][1005][2];
char z[] = " AB";

void move (int a, int b, int cost)
{
    if (a == 0) m[a] = c[a];
    else if (b == 0) m[b] = 0;

    int add = min (m[a], c[b] - m[b]);
    m[a] -= add;
    m[b] += add;

    if (v[m[1]][m[2]] != 1)
    {
        two t1;
        t1.px = m[1], t1.py = m[2], t1.c = cost+1;
        m[a] += add;
        m[b] -= add;
        t1.x = m[1], t1.y = m[2];
        q.push (t1);
        return;
    }
    m[a] += add;
    m[b] -= add;

    return;
}

void pseq (int a, int b, int x, int y, int len)
{
    if (len == 0) return;
    pseq (x, y, p[x][y][0], p[x][y][1], len-1);

    if(a == x) {
            if (b > y) printf ("fill %c\n", z[2]);
            else printf ("empty %c\n", z[2]);
    }
    else if(b == y) {
        if (a > x) printf ("fill %c\n", z[1]);
        else printf ("empty %c\n", z[1]);
    }
    else {
           if (a > x) printf ("pour %c %c\n", z[2],z[1]);
           else  printf ("pour %c %c\n", z[1],z[2]);
    }

    return;
}

int main ()
{
    two t1, t2;
    int i, j, k, n;

    while (cin >> c[1] >> c[2] >> n)
    {
        c[0] = c[2];
        m[1] = m[2] = 0;

        memset (v, 0, sizeof (v));

        t1.px = 0, t1.py = 0, t1.c = 0, t1.x = t1.y = 0;
        q.push (t1);

        while (!q.empty())
        {
            t1 = q.front();
            q.pop();

            if (v[t1.px][t1.py]) continue;
            if (t1.py == n)
                    break;

            v[t1.px][t1.py] = 1;
            p[t1.px][t1.py][0] = t1.x, p[t1.px][t1.py][1] = t1.y;
            m[1] = t1.px, m[2] = t1.py;

            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    if (i != j)
                        move (i,j,t1.c);
        }
        pseq (t1.px, t1.py, t1.x, t1.y, t1.c);
        cout << "success\n";

        while (!q.empty()) q.pop();
    }
    return 0;
}
