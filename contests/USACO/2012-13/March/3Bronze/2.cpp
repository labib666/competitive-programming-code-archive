/*
ID: Labib Rashid
LANG: C++
TASK: proximity
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

using namespace std;

int c[1000005], q[50005];

int main()
{
    int n, i, j, k, ans;
    freopen ("proximity.in","r",stdin);
    freopen ("proximity.out","w",stdout);

    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> q[i];

    memset(c, 0, sizeof (c));

    ans = -1;
    for (i = 0; i <= k; i++){
        c[q[i]]++;
        if ((c[q[i]] > 1) && ans < q[i])
            ans = q[i];
    }

    for (i = 0, j = k + 1; j < n; j++, i++)
    {
        c[q[i]]--;
        c[q[j]]++;
        if ((c[q[j]] - 1) && ans < q[j])
            ans = q[j];
    }

    cout << ans << endl;

    return 0;
}
