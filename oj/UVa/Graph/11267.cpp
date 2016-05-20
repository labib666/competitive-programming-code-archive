/*
UVa
graph
11267 - hire a coder
4.4.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace std;

struct edge {
    int u, v, w;
    bool operator < (const edge &p) const {
        return w < p.w;
    }
};

int p[205], v[205];
edge e[12000];
vector <int> l[205];

int fup (int a)
{
    if (p[a] == a) return a;

    int ans = fup (p[a]);
    p[a] = ans;
    return ans;
}

bool dfs (int a, int val)
{
    v[a] = val;

    for (int i = 0; i < (int) l[a].size (); i++)
    {
        int j = l[a][i];

        if (v[j] == val) return false;
        if (v[j] != -1) continue;
        if (!dfs (j, (1+val)%2)) return false;
    }
    return true;
}

int main ()
{
    int n, m, i;

    while (1)
    {
        cin >> n;
        if (!n) break;
        for (i = 0; i <= n; i++)
            l[i].clear ();

        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> e[i].u >> e[i].v >> e[i].w;
            l[e[i].u].push_back (e[i].v);
            l[e[i].v].push_back (e[i].u);
        }

        memset (v, -1, sizeof (v));

        if (!dfs (1,1)) {
            cout << "Invalid data, Idiot!\n";
            continue;
        }

        for (i = 1; i <= n; i++)
            p[i] = i;
        sort (e, e+m);

        int ans = 0;
        for (i = 0; i < m; i++)
        {
            int pa, pb;
            pa = fup (e[i].u), pb = fup (e[i].v);

            if (pa == pb)
                if (e[i].w >= 0) continue;

            ans += e[i].w;
            p[pa] = pb;
        }

        cout << ans << endl;
    }

    return 0;
}
