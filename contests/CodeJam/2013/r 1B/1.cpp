/*
ID: Labib Rashid
LANG: C++
TASK:
*/

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
# define pi 2*asin(1)

using namespace std;

ll a[1000], n;

ll solve (int p, int s)
{
    //cout << p << s << endl;
    ll a1, a2, ans;

    if (s == 1)
        return n;

    if (p == n)
        return 0;

    a1 = n - p;

    a2 = 0;
    while (s <= a[p])
    {
        s += s-1;
        a2 ++;
    }

    a2 += solve(p+1,s+a[p]);

    return ans = min (a1, a2);
}

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.txt","w",stdout);

    ll i, j, k, t, tc = 0, ans;

    cin >> t;

    while (tc < t)
    {
        tc++;

        cin >> k >> n;

        for (i = 0; i < n; i++)
            cin >> a[i];

        sort (a, a+n);

        ans = solve (0, k);

        printf ("Case #%lld: %lld\n", tc, ans);
    }

    return 0;
}

