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
# define inf 10000000000000007

using namespace std;

struct cow {
    int h, m;
    bool operator < (const cow &p) const {
        if (m == p.m) {
            return h < p.h;
        }
        else return m < p.m;
    }
};

cow c[200005];
ll cn [200005];

int bs (int a) {
    int hi, lo, mid;
    lo = 0, hi = a;

    while (hi >= lo) {
        mid = (hi + lo)/2;

        if (cn[mid] <= c[a].m)
            lo = mid + 1;
        else hi = mid - 1;
    }

    return lo;
}

int main()
{
    int n, i, j, k, ans = 0;
    ll hi = 0;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> c[i].h >> c[i].m;

    for (i = 1; i <= n; i++)
    	cn[i] = inf;
    cn[0] = 0;

    sort (c, c+n);

    for (i = 0; i < n; i++)
    {
        k = bs (i);
        //cout << k << endl;
        for (j = k; j > 0; j--){
            if (cn[j-1] + c[i].h < cn[j])
                cn[j] = cn[j-1] + c[i].h;
        }
        //for (j = 0; j <= n; j++)
            //cout << cn[j] << " ";
        //cout << endl;
    }

    for (i = 0; i <= n; i++)
        if (cn[i] >= inf)
            break;
    ans = i - 1;

    cout << ans << endl;

    return 0;
}


