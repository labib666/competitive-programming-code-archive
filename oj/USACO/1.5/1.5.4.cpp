/*
USACO
recursion
1.5.4 - Checker Challenge
27.2.1013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: checker
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <sstream>
# include <vector>

using namespace std;

int g[15][15], n, c, res [15];

inline void process (int a, int b)
{
    int i, j;

    for (i=a+1; i <= n; i++) g[i][b] += 1;

    for (i= b-1, j = a+1; i>0; i--,j++){
        if (j > n) break;
        g[j][i] += 1;
    }

    for (i= b+1, j = a+1; i<=n; i++,j++){
        if (j > n) break;
        g[j][i] += 1;
    }

    return;
}

inline void revprocess (int a, int b)
{
    int i, j;

    for (i=a+1; i <= n; i++) g[i][b] -= 1;

    for (i= b-1, j = a+1; i>0; i--,j++){
        if (j > n) break;
        g[j][i] -= 1;
    }

    for (i= b+1, j = a+1; i<=n; i++,j++){
        if (j > n) break;
        g[j][i] -= 1;
    }

    return;
}

inline void printres ()
{
    int j;
    printf ("%d", res[1]);
    for (j=2; j<= n; j++) printf (" %d", res[j]);
    printf ("\n");
    return;
}

inline void findres (int len)
{
    int i;
    if (len == n)
    {
        for (i=1; i<= n; i++){
            if (g[n][i]) continue;
            c++;
            if (c > 3) continue;
            res [n] = i;
            printres();
        }
        return;
    }

    for (i=1; i<= n; i++)
    {
        if (g[len][i]) continue;
        process (len,i);
        if (c < 3) res [len] = i;
        findres (len+1);
        revprocess(len,i);
    }
    return;
}

int main()
{
    freopen ("checker.in","r", stdin);
    freopen ("checker.out","w", stdout);

    cin >> n;
    c = 0;
    memset (g, 0, sizeof(g));
    findres (1);
    cout << c << endl;
    return 0;
}
