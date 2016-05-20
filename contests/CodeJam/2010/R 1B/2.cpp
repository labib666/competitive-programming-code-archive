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

int p[55], v[55];

int main()
{
    int T, tc = 0, n, k, b, t, i, x, y, z, ans;

    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.txt", "w", stdout);

    cin >> T;
    while (tc < T)
    {
        ++tc;

        cin >> n >> k >> b >> t;

        for (i = n-1; i >= 0; i--)
            cin >> p[i];
        for (i = n-1; i >= 0; i--)
            cin >> v[i];

        ans = 0;

        for (i = 0; k && i < n; i++)
        {
            x = b - p[i];
            y = x/v[i];
            if (x % v[i]) y++;

            if (y > t) {
                ans += k;
                continue;
            }

            k--;
        }
        if (k) printf ("Case #%d: IMPOSSIBLE\n", tc);
        else printf ("Case #%d: %d\n", tc, ans);
    }

    return 0;
}

