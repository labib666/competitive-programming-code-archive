/*
UVa
graph
10305 - ordering tasks
5.3.2013
*/

# include <cstdio>
# include <iostream>
# include <vector>
# include <cstring>

using namespace std;

int v [105], n;
vector <int> c[105];

void move (int k)
{
    if (k == 0) {
        cout << endl;
        return;
    }

    for (int i = 1; i<=n; i++)
    {
        if (v[i]) continue;
        int res = 1;
        for (int j = 0; j<(int)c[i].size(); j++)
        {
            if (v[c[i][j]]) continue;
            res = 0;
            break;
        }
        if (res)
        {
            if (n-k) cout << " " << i ;
            else cout << i ;

            v[i] = 1;
            move(k-1);
            return;
        }
    }

    return;
}

int main()
{
    int m, i, j, x, y;
    while (1)
    {
        cin >> n >> m;
        if (n + m == 0) break;

        fill (v,v+n+1, 0);
        for (i=0; i<m; i++)
        {
            cin >> x >> y;
            c[y].push_back(x);
        }

        move(n);

        for (i=1; i<=n; i++) c[i].clear();
    }
    return 0;
}
