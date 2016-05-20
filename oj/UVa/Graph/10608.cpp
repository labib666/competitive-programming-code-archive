/*
UVa
graph
10608 - friends
10.3.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>

using namespace std;

vector <int> e[30005];
int v[30005], c[30005];
int ans, cnt;

void flood (int a)
{
    v[a] = 1;
    cnt++;
    for (int i = 0; i < e[a].size(); i++)
    {
        if (v[e[a][i]]) continue;
        flood (e[a][i]);
    }
    return;
}

int main()
{
    int t, n, m, x, y, i, j, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        for (i = 0; i <= n; i++) e[i].clear();
        memset (c, -1, sizeof(c));

        for (i = 0; i < m; i++){
            cin >> x >> y;
            e[x].push_back (y);
            e[y].push_back (x);
        }
        k = 0, ans = 1;
        for (i = 1; i <= n; i++) {
            if (c[i] != -1) continue;
            memset (v, 0, sizeof (v));
            cnt = 0;
            flood (i);
            ans = max (ans, cnt);
            k++;
        }

        cout << ans << endl;
    }
    return 0;
}
