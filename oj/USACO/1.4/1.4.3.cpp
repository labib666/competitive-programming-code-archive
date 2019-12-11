/*
USACO
search
1.4.3 - arithmetic progressions
25.2.2013
*/

/*
ID: Labib Rashid
LANG: C++
TASK: ariprog
*/

# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>
# include <utility>
# include <vector>
# define f first
# define s second

using namespace std;

int is[130000], bi[32000];
vector < pair <int,int> > res;

int main ()
{
    int n, m, i, j, k, bimax, d, last, v;
    pair <int,int> r;

    freopen ("ariprog.in", "r", stdin);
    freopen ("ariprog.out", "w", stdout);

    cin >> n >> m;
    bimax = 2*m*m;

    fill (is, is+bimax+1, 0);

    for (i=0; i<=m; i++)
        for (j=i; j<=m; j++)
            is [i*i + j*j] = 1;

    m = 0;
    for (i=0; i<= bimax; i++)
        if (is[i])
            bi [m++] = i;

    for (i=0;i<m;i++)
    {
        for (j=i+1;j<m;j++)
        {
            d = bi[j] - bi[i];

            last = bi[i] + d*(n-1);

            if (last > bimax) break;

            if (is[last]) {
                v = 1;
                for (k = 2; k < n - 1; k++)
                {
                    if (is[bi[i] + d*k]) continue;
                    else {
                        v = 0;
                        break;
                    }
                }

                if (v)
                {
                    r.f = d;
                    r.s = bi [i];

                    res.push_back (r);
                }
            }
        }
    }

    sort (res.begin(), res.end());
    if ((int)res.size())
        for (i=0;i < (int)res.size(); i++)
            cout << res[i].s << " " << res[i].f << endl;
    else cout << "NONE\n";

    return 0;
}
