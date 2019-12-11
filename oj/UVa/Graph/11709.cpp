/*
UVa
graph
11709 - trust groups
3.4.2013
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <map>
# include <string>
# include <vector>

using namespace std;

vector <int> e[1005];
map <string,int> m;
int vis[1005][1005], n, c[1005];

void dfs (int a, int b)
{
    vis[b][a] = 1;
    for (int i = 0; i < (int)e[a].size(); i++){
        int j = e[a][i];
        if (vis[b][j]) continue;
        dfs (j,b);
    }
    return;
}

void process (int a, int cnt) {
    int i, j;

    for (i = 1; i <= n; i++)
    {
        if (vis[a][i] & vis[i][a])
            c[i] = cnt;
    }
    return;
}

int main()
{
    int t, i, j, k, cnt;
    string str1, str2;
    char s1[1000], s2[1005];

    while (1)
    {
        cin >> n >> t;
        if (n + t == 0) break;
        gets (s1);
        memset (vis, 0, sizeof (vis));
        memset (c, -1, sizeof (c));
        cnt = 0;

        for (i = 1; i <= n; i++) {
            gets (s1);
            str1 = s1;
            m[str1] = i;
        }

        while (t--) {
            gets (s1);
            gets (s2);

            str1 = s1, str2 = s2;
            j = m[str1], k = m[str2];

            e[j].push_back (k);
        }

        for (i = 1; i <= n; i++)
            dfs (i,i);

        for (i = 1; i <= n; i++)
        {
            if (c[i] == -1) {
                process (i, cnt);
                cnt ++;
            }
        }

        cout << cnt << endl;

        for (i = 1;i <= n;i++)
            e[i].clear();
        m.clear();
    }
    return 0;
}
