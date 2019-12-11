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
# define inf 707106780ll
# define pi 2*asin(1)

using namespace std;

ll r, v;

ll bs ()
{
    ll hi, lo, mid, cur;

    lo = 1, hi = min (inf,v/(2*r));

    while (hi >= lo)
    {
        mid = (hi+lo)/2;

        cur = mid*2*r;
        cur += (mid*(2*1 + (mid-1)*4))/2;

        //cout << mid << " >> " << cur << " & " << v <<  endl;

        if (cur > v) hi = mid - 1;
        else lo = mid + 1;
    }

    return lo - 1;
}

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("A-large-practice.in","r",stdin);
    freopen ("A-large-practice.txt","w",stdout);

    ll ans, i, j, k, t, tc = 0;

    cin >> t;
    while (tc < t)
    {
        ++tc;

        cin >> r >> v;

        ans = bs();

        printf ("Case #%lld: %lld\n", tc, ans);
    }

    return 0;
}

