/*
UVa
graph
247 - calling circles
23.3.2013
*/

# include <cstdio>
# include <cstring>
# include <vector>
# include <map>
# include <string>
# include <iostream>

using namespace std;

int c[30][30];
vector <int> e[30];

void flow (int a, int k)
{
    if (a != k)
        c[k][a] = 1;

    for (int i = 0; i < (int)e[a].size(); i++)
    {
        int j = e[a][i];
        if (c[k][j])
            continue;
        flow(j, k);
    }
    return;
}

int main()
{
    int t = 0, i, j, k, mp, n, cnt, d[30], co;
    map <string, int> m;
    string s[30], s1, s2;

    while (1)
    {
        cin >> n >> mp;
        if (n + mp == 0)
            break;
        if (t)
            cout << endl;
        ++t;

        m.clear();
        for (i = 1; i <= n; i++){
            fill (c[i]+1, c[i]+n+1, 0);
            e[i].clear();
        }
        cnt = 1;

        while (mp--)
        {
            cin >> s1 >> s2;

            if (!m[s1]) {
                    m[s1] = cnt++;
                    s[m[s1]] = s1;
            }
            if (!m[s2]) {
                    m[s2] = cnt++;
                    s[m[s2]] = s2;
            }

            e[m[s1]].push_back(m[s2]);
        }

        for (i = 1; i <= n; i++)
            flow (i,i);

        memset(d, -1, sizeof (d));
        co = 0;

        for (i = 1; i <= n; i++)
        {
            if (d[i] == -1)
            {
                d[i] = co;
                for (j = i+1; j <= n; j++)
                {
                    if ((c[i][j] & c[j][i]) && d[j] == -1)
                        d[j] = co;
                }
                co++;
            }
        }

        printf ("Calling circles for data set %d:\n", t);
        for (i = 0; i < co; i++)
        {
            k = 0;
            for (j = 1; j <= n; j++)
            {
                if (d[j] ==i){
                    if (k) cout << ", ";
                    k++;
                    cout << s[j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
