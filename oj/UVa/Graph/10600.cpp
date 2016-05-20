/*
UVa
10600 - 10600 - ACM Contest and Blackout
graph - mst
15.3.2013
*/

# include <cstdio>
# include <iostream>
# include <iostream>
# include <vector>
# include <algorithm>
# include <vector>

using namespace std;

struct edge {
    int u, v, w;
    bool operator < (const edge &p) const {
        return w < p.w;
    }
};

int p[105];
edge e[10005];
vector <int> take;

int fup (int a)
{
    if (p[a] == a) return a;
    int ans = fup (p[a]);
    p[a] = ans;
    return ans;
}

int main()
{
    int t, i, j, k, m, n;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (i = 0; i < m; i++)
            cin >> e[i].u >> e[i].v >> e[i].w;

        for (i = 1; i <= n; i++)
            p[i] = i;
        sort (e, e+m);

        int cost1 = 0, cost2 = 0x33333333, cost3, l;
        int tst = 0;
        for (i = 0; i < m; i++)
        {
            int p1 = fup (e[i].u), p2 = fup (e[i].v);
            if (p1 == p2) {
                continue;
            }
            cost1 += e[i].w;
            p[p2] = p1;
            take.push_back (i);
        }

        for (j = 0; j < (int)take.size(); j++)
        {
            for (i = 1; i <=n ; i++)
                p[i]=i;
            k = take[j];
            cost3 = 0, l = 0;
            for (i = 0; i < m; i++)
            {
                if (k == i) continue;
                int p1 = fup (e[i].u), p2 = fup (e[i].v);
                if (p1 == p2)
                    continue;
                cost3 += e[i].w;
                p[p2] = p1;
                l++;
            }

            if (cost3 < cost2 && l == n-1) cost2 = cost3;
        }

        cout << cost1 << " " << cost2 << endl;
        take.clear();
    }
    return 0;
}
