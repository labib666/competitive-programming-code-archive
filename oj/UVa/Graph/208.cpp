/*
UVa
graph
208 - firetruck
9.3.2013
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace std;

vector <int> e[25];
int v[25], p[25], f[25], ans, n;

void print (int a)
{
    cout << p[0];
    for (int i = 1; i <= a; i++)
        cout << " " << p[i];
    cout << endl;
    return;
}

void flow (int a, int k)
{
    int i, j;

    v[a] = 1;
    p[k] = a;

    if (a == n)
    {
        ans++;
        print (k);
    }

    else {
    for (i=0; i < (int)e[a].size(); i++)
    {
        if (v[e[a][i]]) continue;
        if (f[e[a][i]]) flow (e[a][i], k+1);
    }
    }

    v[a] = 0;
    return;
}

void flag (int a)
{
    int i;
    f[a] = 1;
    for (i=0; i < (int)e[a].size(); i++)
    {
        if (f[e[a][i]]) continue;
        flag (e[a][i]);
    }
    return;
}

int main()
{
    int i, j, k, cnt = 1;

    while (scanf ("%d", &n) != EOF)
    {
        while (1)
        {
            scanf ("%d %d", &i, &j);
            if (i + j == 0) break;

            e[i].push_back (j);
            e[j].push_back (i);
        }

        ans = 0;
        memset (f, 0, sizeof(f));
        flag (n);

        for (i=0; i<21; i++) sort (e[i].begin(), e[i].end());

        printf ("CASE %d:\n", cnt++);
        flow (1, 0);
        printf ("There are %d routes from the firestation to streetcorner %d.\n", ans, n);

        for (i=0; i<21;i++) e[i].clear();
    }
    return 0;
}
