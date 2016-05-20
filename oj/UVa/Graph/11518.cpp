/*
UVa
Graph
11518 - dominos (ii)
5.3.2013
*/

# include <cstdio>
# include <iostream>
# include <vector>

using namespace std;

int f [10005];
vector <int> d[10005];

int flow (int a, int val)
{
    //if (a == -1) return val;
    if(f[a]) return 0;

    f[a] = 1;
    int ans = 1;
    for (int i = 0; i < (int)d[a].size(); i++) ans += flow (d[a][i], val+1);
    return ans;
}

int main()
{
    int n, m, l, i, x, y, ans, t;
    vector <int> move;

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> l;
        fill (f, f+n+1, 0);
        //fill (d, d+n+1, -1);

        for (i=0; i<m; i++)
        {
            cin >> x >> y;
            d[x].push_back (y);
        }

        for (i=0; i<l; i++)
        {
            cin >> x;
            move.push_back(x);
        }

        ans = 0;
        for (i=0; i<l; i++)
            ans += flow(move[i], 0);

        cout << ans << endl;
        move.clear();
        for (i=1;i<=n;i++) d[i].clear();
    }
    return 0;
}
