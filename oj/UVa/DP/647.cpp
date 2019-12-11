/*
UVa
DP
647 - chutes and ladders
01.2.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <map>
# include <cstdlib>

using namespace std;

int move[1000], pos[6], grid[101], n, miss[6];
map <int,int> t;

inline int go(int a, int b)
{
    if (miss[a] == 1) {
        miss[a] = 0;
        return go((a+1)%n,b);
    }

    if (pos[a] + move[b] > 100) return go((a+1)%n,b+1);

    if (pos[a] + move[b] == 100) return a + 1;

    pos[a] = grid [pos[a] + move[b]];

    if (t[pos[a]] == 1) return go(a,b+1);
    if (t[pos[a]] == -1) miss[a] = 1;

    return go((a+1)%n,b+1);
}

int main()
{
    int c = 0, m, i, a, b, win;
    while (1)
    {
        cin >> m;
        if (m == 0) break;
        move[c++] = m;
    }

    while (1)
    {
        cin >> n;
        if (n == 0) break;

        memset (pos, 0, sizeof(pos));
        memset (miss, 0, sizeof(miss));
        for (i = 0; i<101; i++) {
            grid[i] = i;
            t[i] = 0;
        }

        while (1)
        {
            cin >> a >> b;
            if (a==0 && b==0) break;

            grid[a] = b;
        }

        while (1)
        {
            cin >> a;
            if (a == 0) break;

            if (a < 0) t[abs(a)] = -1;
            else t[abs(a)] = 1;
        }

        win = go (0, 0);
        cout << win << endl;
    }

    return 0;
}
