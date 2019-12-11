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

using namespace std;

struct data {
    int p, c;
    bool operator < (const data &k) const {
        return p < k.p;
    }
};

data cs[1005];

int main()
{
    int n, d, i, j, k;
    long long ans = 0;
    cin >> n >> d;
    for (i = 0; i < n; i++)
    {
        cin >> cs[i].c >> cs[i].p;
    }
    sort (cs, cs+n);

    for (i = 0; i < n; i++)
    {
        ans += min(d, cs[i].c)*cs[i].p;
        d -= min(d, cs[i].c);
        if (!d) break;
    }

    cout << ans << endl;

    return 0;
}
