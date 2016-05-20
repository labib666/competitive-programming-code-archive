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
#include <cstring>
#include <queue>

#define ll long long
#define pb push_back
#define x first
#define y second
#define inf 1000000007ll
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

ll n, a[300005], b[300005];

ll check (ll h) {
    ll i, sum = 0;
    for (i = 0; i < n; i++) {
        if (i <= n/2)
            sum += abs (h-i-a[i]) + abs (h-i-b[i]);
        else
            sum += abs (h-(n-1-i)-a[i]) + abs (h-(n-1-i)-b[i]);
    }
    return sum;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    ll i, j, k, hi, lo, m1, m2;

    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++) cin >> b[i];

    hi=1000000000000+300000;
    lo=n/2;

    while (hi>lo+3) {
        m1 = (hi-lo)/3;
        m2 = 2*m1;
        ll v1, v2;
        v1 = check (lo+m1);
        v2 = check (lo+m2);
        if (v1 <= v2) hi = lo+m2;
        else lo = lo+m1;
    }
    ll ans = inf*inf;
    for (i=lo;i<=hi;i++) {
        ans = min(ans, check(i));
    }

    cout << ans << endl;


    return 0;
}
