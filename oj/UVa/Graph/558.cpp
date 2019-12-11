/*
UVa
558 - warmholes
graph - bellman ford
9.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# define inf 1000000007

using namespace std;

struct edge {
    int u, v, w;
};

edge e[2005];
int d[1005], n, m;

void relax (int i, int j, int k)
{
    if (d[i] > d[j] + k)
        d[i] = d[j] + k;
    return;
}

bool bford ()
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            relax(e[j].v, e[j].u, e[j].w);

    for (j = 0; j < m; j++)
        if (d[e[j].v] > d[e[j].u] + e[j].w)
            return false;

    return true;
}

int main ()
{
    int t, i, j;
    bool ans;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (i = 0; i <m; i++)
            cin >> e[i].u >> e[i].v >> e[i].w;

        fill (d + 1, d + n, inf);
        d[0] = 0;

        ans = bford();

        if (ans == false)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
    return 0;
}
