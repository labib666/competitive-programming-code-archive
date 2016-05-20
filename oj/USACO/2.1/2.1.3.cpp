/*
USACO
2.1.3 - sort3
sorting, greedy
16.3.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: sort3
*/

# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
    freopen ("sort3.in", "r", stdin);
    freopen ("sort3.out", "w", stdout);

    int s[1005], c[1005], m[4][4], i, j, k, a, n;
    cin >> n;

    fill (c, c+4, 0);
    for (i = 1; i <= n; i++){
        cin >> s[i];
        c[i] = s[i];
    }
    sort (c, c+n+1);
    memset(m, 0, sizeof(m));

    for (i = 1; i <=n; i++)
        m[s[i]][c[i]]++;

    a = 0;
    for (i = 1; i <= 3; i++)
    {
        for (j = i+1; j <= 3; j++)
        {
            k = min (m[i][j], m[j][i]);
            a += k;

            m[i][j] -= k;
            m[j][i] -= k;
        }
        m[i][i] = 0;
    }

    k = max (m[2][1], m[3][1]);
    a += 2*k;

    cout << a << endl;

    return 0;
}
