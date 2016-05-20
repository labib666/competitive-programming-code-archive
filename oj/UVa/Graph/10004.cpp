/*
UVa
graph - f.fill
10004 - bicoloring
5.3.2013
*/

# include <cstdio>
# include <iostream>
# include <vector>

using namespace std;

vector <int> e[205];
int c[205];

inline int flood (int a, int v)
{
    c[a] = v;

    int i, r;
    for (i = 0; i< (int) e[a].size(); i++)
    {
        if (c[e[a][i]] == -1) {
            r = flood(e[a][i], (v+1)%2);
            if (r) continue;
            else return 0;
        }

        else
            if (c[e[a][i]] == v) return 0;
    }

    return 1;
}

int main()
{
    int n, m, i, x, y;

    while (1)
    {
        cin >> n;
        if (n == 0) break;

        cin >> m;
        fill (c, c+n, -1);

        for (i=0; i<m; i++)
        {
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        int ans = flood(0, 0);

        if (ans) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";

        for (i=0; i < n; i++)
            e[i].clear();
    }
    return 0;
}
