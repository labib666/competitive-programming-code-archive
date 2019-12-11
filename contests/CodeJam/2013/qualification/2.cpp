#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
# include <cstring>
# include <queue>
# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007

using namespace std;

int a[105][105], rm[105], cm[105];

int main()
{
    int t, tc = 0, n, m, i, j, k;

    freopen ("B-large.in", "r", stdin);
    freopen ("B-large.txt", "w", stdout);

    cin >> t;
    while (tc < t)
    {
        ++tc;

        cin >> n >> m;
        for (i = 0; i < max(n,m); i++)
            rm[i] = cm[i] = -1 * inf;

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                cin >> a[i][j];

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                rm[i] = max (rm[i],a[i][j]);

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cm[i] = max (cm[i],a[j][i]);

        int fail = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                if (a[i][j] < rm[i] && a[i][j] < cm[j]) {
                    fail = 1;
                    break;
                }
            }
            if (fail) break;
        }

        if (fail) printf ("Case #%d: NO\n", tc);
        else printf ("Case #%d: YES\n", tc);
    }

    return 0;
}

