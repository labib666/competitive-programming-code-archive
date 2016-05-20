/*
UVa
280 - vertex
graph
7.3.2013
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <queue>
# include <vector>

using namespace std;

int c[105];
vector <int> d[105];

inline void flow (int b)
{
    for (int i = 0; i < (int) d[b].size(); i++)
    {
        if (c[d[b][i]]) continue;
        c[d[b][i]] = 1;
        flow (d[b][i]);
    }
    return;
}

int main()
{
    int n, k, m, i, j, l;
    queue <int> a;
    while (1)
    {
        cin >> n;
        if (n == 0) break;

        while (1)
        {
            cin >> k;
            if (k == 0) break;

            while (1)
            {
                cin >> m;
                if (m == 0) break;

                d[k].push_back (m);
            }
        }

        cin >> m;
        while (m--)
        {
            cin >> k;
            fill (c, c+n+1, 0);
            flow (k);

            for (i=1;i<=n;i++) if (c[i] != 1) a.push(i);
            cout << (int) a.size() ;
            while (!a.empty()) {
                    cout << " " << a.front() ;
                    a.pop();
            }
            cout << endl;
        }
        for (i=1; i <= n; i++ ) d[i].clear();
    }
    return 0;
}
