/*
UVa
graph
10583 - ubiquitous number
9.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>

using namespace std;

vector <int> e[50005];
int c[50005], ans;

inline void flood(int a)
{
    c[a] = ans;

    for (int i=0; i < (int)e[a].size(); i++)
        if (c[e[a][i]] == -1)
            flood (e[a][i]);

    return;
}

int main()
{
    int n, m, i, j, k, cnt = 1;

    while (1)
    {
        cin >> n >> m;
        if (n + m == 0) break;

        memset (c, -1, sizeof (c));
        for (i = 1; i <= n; i++) e[i].clear();

        while (m--)
        {
            cin >> j >> k;
            e[j].push_back (k);
            e[k].push_back (j);
        }
        ans = 0;
        for (i = 1; i <= n; i++) {
            if (c[i] != -1) continue;
            ans ++;
            flood (i);
        }

        printf ("Case %d: %d\n", cnt++, ans);
    }
    return 0;
}
