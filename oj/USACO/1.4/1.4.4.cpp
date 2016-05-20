/*
USACO
search
1.4.4 - mother's milk
24.2.2013
*/

/*
ID: Labib Rashid
LANG: C++
TASK: milk3
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>

using namespace std;

struct data {
    int da, db, dc;
};

int m[3];
int c[3];
queue <data> q;
vector <int> res;
int vis[21][21][21];

void move(int x, int y)
{
    if (m[x] == 0) return;

    int temp = min (m[x], c[y] - m[y]);

    m[x] -= temp;
    m[y] += temp;

    data n;
    n.da = m[0], n.db = m[1], n.dc = m[2];
    if (vis [n.da][n.db][n.dc] == 1) {
        m[x] += temp;
        m[y] -= temp;
        return;
    }

    q.push(n);

    m[x] += temp;
    m[y] -= temp;

    return;
}

int main()
{
    int i, j;

    freopen ("milk3.in", "r", stdin);
    freopen ("milk3.out", "w", stdout);

    cin >> c[0] >> c[1] >> c[2];
    c[0] = min (c[0], c[2]);
    c[1] = min (c[1], c[2]);

    data n;
    n.da = 0, n.db = 0, n.dc = c[2];

    q.push(n);

    while (!q.empty())
    {
        n = q.front();
        q.pop();

        m[0] = n.da, m[1] = n.db, m[2] = n.dc;
        if (vis[n.da][n.db][n.dc] == 1) continue;

        vis[n.da][n.db][n.dc] = 1;
        if (n.da == 0) res.push_back (n.dc);

        for (i=0; i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (i == j) continue;
                move(i,j);
            }
        }
    }

    sort (res.begin(),res.end());
    cout << res[0];
    for (i=1; i<res.size();i++) cout << " " << res[i];
    cout << endl;

    return 0;
}
