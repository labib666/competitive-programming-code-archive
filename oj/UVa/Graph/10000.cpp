/*
UVa
10000 - Longest Path
DP + Search
08.01.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <vector>

using namespace std;

int lp[101], fp[101];
vector <int> road[101];

int dfs(int a)
{
    if (lp[a] != -1)
        return lp[a];

    if (road[a].size() == 0)
    {
        fp[a] = a;
        lp[a] = 0;
        return 0;
    }

    int i,j,m;
    m = -1;

    for (i=0; i<road[a].size(); i++)
    {
        j = road[a][i];
            if (m == 1+dfs(j))
                fp[a] = min(fp[a],fp[j]);
            else if(m < 1+dfs(j))
            {
                fp[a] = fp[j];
                m = 1+dfs(j);
            }
    }

    lp[a] = m;
    return m;
}

int main()
{
    int n, x, y, start, i = 0;

    while (1)
    {
        memset (lp, -1, sizeof(lp));
        for (int j=0; j<=100; j++) fp[j] = 150;
        i++;

        scanf ("%d", &n);
        if (n == 0) break;

        scanf ("%d", &start);

        while (1)
        {
            scanf ("%d %d", &x, &y);
            if (x == 0 && y == 0) break;

            road[x].push_back(y);
        }

        dfs (start);

        printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", i, start, lp[start], fp[start]);

        for (int j=0; j<=100; j++)
            road[j].clear();
    }

    return 0;
}
