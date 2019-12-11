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

int dp[1000005];
data cs[1005];
int go [100005];

int main()
{
    int n, d, i, j, k;
    cin >> n >> d;
    for (i = 0; i < n; i++)
    {
        cin >> cs[i].c >> cs[i].p;
    }
    sort (cs, cs+n);

    for (i = 1; i <= d; i++)
        dp[i] = 1000000007;
    dp [0] = 0;

    for (i = 0; i < n; i++)
    {
        fill (go, go + d+1, 0);
        for (j = 1; j <= d; j++)
        {
            if (dp[j] > dp[j-1] + cs[i].p){
                go[j] = go[j-1]+1;
                if (go[j] > cs[i].c) break;
                dp[j] = dp[j-1] + cs[i].p;
            }
        }
    }

    cout << dp[d] << endl;

    return 0;
}
