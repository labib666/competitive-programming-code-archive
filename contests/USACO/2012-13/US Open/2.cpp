/*
ID: Labib Rashid
LANG: C++
TASK: fuel
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
# define inf 10000000000000007

using namespace std;

int d[50005], c[50005], dp[50005], f[50005];

int main ()
{
    int n, g, b, dst, cst, i, j, k;

    cin >> n >> g >> b >> d[n+1];

    for (i = 1; i <= n; i++){
        cin >> d[i] >> c[i];
        dp[i] = inf;
    }

    d[0] = 0, c[0] = 0, dp[0] = 0;

    for(j=1; j<=n+1;j++)
        if (d[j] <= b) {
            f[j] = b - d[j];
            dp[j] = 0;
        }

    for (i=1; i<=n; i++)
    {
        for(j=i+1; j<=n+1;j++)
        {
            dst = d[j] - d[i];
            if (dst > f[i])
            {
                cst = ds
            }
        }
    }
}
