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

using namespace std;

vector <ll> s[2];
ll a, b, n, x, y;
ll arr[40];

void flow (ll i, ll j, ll k, ll sum) {
    if (i > j) {
        s[k].pb (sum);
        return;
    }
    flow(i+1, j, k, sum+arr[i]);
    flow(i+1, j, k, sum);

    return;
}

ll bs (ll f, ll g) {
    ll hi, lo, mid;
    hi = s[1].size()-1;
    lo = 0;

    while (hi >= lo) {
        mid = (hi+lo)/2;
        if (s[1][mid] > g) hi = mid - 1;
        else {
            if (!f && s[1][mid] == g) return mid;
            else lo = mid + 1;
        }
    }

    return lo;
}

int main()
{
    ll i, j , k;
    ll sum;

    cin >> n >> a >> b;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    x = n/2;
    y = x+1;

    flow (0,x,0,0);
    flow (y,n-1,1,0);

    sort (s[0].begin(), s[0].end());
    sort (s[1].begin(), s[1].end());

    x = (ll)s[0].size();
    y = (ll)s[1].size();

    ll ans = 0;

    for (i=0; i < x; i++) {
        j = a - s[0][i];
        k = b - s[0][i];

        ans += upper_bound(s[1].begin(),s[1].begin()+y,k) - lower_bound(s[1].begin() , s[1].begin() + y, j);
    }
    cout << ans << endl;

    return 0;
}

