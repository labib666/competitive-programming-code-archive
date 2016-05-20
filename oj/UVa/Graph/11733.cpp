/*
UVa
MST
11733 - Air Ports
13.03.13
*/

# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <cstring>

using namespace std;

struct edge {
    int u, c;
    bool operator < (const edge &p) const{
        return c > p.c;
    }
};

int main()
{
    int t, i, j, v, n, m, c, ap;
    edge cc, pc;
    int val[10001], visited[10001];
    vector <int> cost[10001], city[10001];
    priority_queue <edge> q;

    scanf ("%d", &t);
    for (i=0; i<t; i++)
    {
        ap = 0;
        memset (val, -1, sizeof (val));
        memset (visited, 0, sizeof(visited));
        for (j=0; j<= 10000; j++)
        {
            cost[j].clear();
            city[j].clear();
        }

        int x,y;

        scanf ("%d %d %d", &n,&m,&c);
        for (j=0; j<m; j++)
        {
            scanf ("%d %d %d", &x, &y, &v);

            if (v > c) v = c;

            cost[x].push_back(v);
            cost[y].push_back(v);

            city[x].push_back(y);
            city[y].push_back(x);
        }

        for (j = 1; j<= n; j++)
        {
            if (val[j] == -1)
            {
                cc.u = j;
                cc.c = c;

                q.push(cc);

                while(!q.empty())
                {
                    pc = q.top();
                    q.pop();

                    x = pc.u;
                    if (visited[x] == 1) continue;
                    visited[x] = 1;
                    val[x] = pc.c;
                    if (pc.c == c) ap++;

                    for (int k=0; k<city[x].size(); k++)
                    {
                        if (visited[city[x][k]] == 1) continue;
                        cc.u = city[x][k];
                        cc.c = cost[x][k];

                        q.push(cc);
                    }
                }
            }
        }

        long long int res = 0;

        for (j=1; j<=n; j++) res += val[j];
        printf ("Case #%d: %lld %d\n", i+1, res, ap);
    }
    return 0;
}
