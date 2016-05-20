/*
ID: Labib Rashid
LANG: C++
TASK: mirrors
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <map>
# include <algorithm>
# include <string>

using namespace std;

inline int compress(int a[202], int p)
{
    map <int, int> tag;
    int i, s[202], n = 1;

    memcpy(s,a,sizeof(s));
    sort (s, s+p);
    for (i=0; i<p;i++)
    {
        if (tag.find(s[i]) == tag.end())
            tag[s[i]] = n++;
    }

    for (i=0; i<p; i++)
        a[i] = tag[a[i]];

    return n;
}

int grid[204][204];
int mirror[204][204];
int check;

int dfs(int a, int b, int x, int y)
{
    if (grid[a][b] == 0) return dfs (a+x, b+y, x, y);

    if (grid[a][b] == 1)
    {
        int p;
        mirror[a][b]++;
        if (mirror[a][b] > 2) {
            mirror[a][b]--;
            return -1;
        }

        if (x == 0)
        {
            if (y == 1)
                p = dfs (a+1, b, 1, 0);
            else
                p = dfs (a-1, b, -1, 0);
        }
        else
        {
            if (x == 1)
                p = dfs (a, b+1, 0, 1);
            else
                p = dfs (a, b-1, 0, -1);
        }
        mirror[a][b]--;
        return p;
    }

    if (grid[a][b] == 2)
    {
        int p;
        mirror[a][b]++;
        if (mirror[a][b] > 2) {
            mirror[a][b]--;
            return -1;
        }

        if (x == 0)
        {
            if (y == 1)
                p = dfs (a-1, b, -1, 0);
            else
                p = dfs (a+1, b, 1, 0);
        }
        else
        {
            if (x == 1)
                p = dfs (a, b-1, 0, -1);
            else
                p = dfs (a, b+1, 0, 1);
        }
        mirror[a][b]--;
        return p;
    }

    if (grid[a][b] == 5) return 1;

    if (grid[a][b] == -1) return -1;
}

int main()
{
    int n, i, a, b;
    int xc[202], yc[202];
    string s[202], s2 = "/";

    freopen ("mirrors.in","r",stdin);
    freopen ("mirrors.out","w",stdout);

    xc[0] = 0;
    yc[0] = 0;
    cin >> n;
    cin >> xc[n+1] >> yc[n+1];

    for (i=1; i<= n; i++)
        cin >> xc[i] >> yc[i] >> s[i];

    a = compress(xc,n+2);
    b = compress(yc,n+2);

    memset (grid, 0, sizeof(grid));

    for(i=0;i<=a+1;i++)
        grid[0][i] = grid[b+1][i] = -1;
    for(i=0;i<=b+1;i++)
        grid[i][0] = grid[i][a+1] = -1;

    for (i=1; i<=n; i++){
        if (s[i] == s2) grid[xc[i]][yc[i]] = 1;
        else grid[xc[i]][yc[i]] = 2;
        mirror [xc[i]][yc[i]] = 0;
    }

    grid[xc[n+1]][yc[n+1]] = 5;

    int res = dfs (xc[0],yc[0],1,0);

    if (res == -1) {
        for (i=1; i<n+1; i++)
        {
            memset(mirror,0,sizeof(mirror));
            if (grid[xc[i]][yc[i]] == 1){
                grid[xc[i]][yc[i]] = 2;
                res = dfs(xc[0],yc[0],1,0);
                if (res == 1) {
                    cout << i << endl;
                    break;
                }

                grid[xc[i]][yc[i]] = 1;
            }

            else if (grid[xc[i]][yc[i]] == 2){
                grid[xc[i]][yc[i]] = 1;
                res = dfs(xc[0],yc[0],1,0);
                if (res == 1) {
                    cout << i << endl;
                    break;
                }

                grid[xc[i]][yc[i]] = 2;
            }
        }
        if (i == n+1)cout << "-1" << endl;
    }
    else cout << "0" << endl;

    return 0;
}
