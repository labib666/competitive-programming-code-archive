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

int dp[140][140], c[140];

int solve (int a, int b){
    if (a == b)
        return c[a];
    if (a == b-1)
        return max (c[a],c[b]);

    if (dp[a][b] != -1)
        return dp[a][b];

    int sum, s1, ans = -1111111;

    s1 = c[a];
    sum = min (solve(a+1,b-1), solve(a+2, b));
    ans = max (ans, s1+sum);

    s1 = c[b];
    sum =min (solve(a+1,b-1), solve(a, b-2));
    ans = max (ans, s1+sum);

    dp[a][b] = ans;
    return ans;
}

int main()
{
    int n, ans, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> c[i];

    memset( dp, -1, sizeof (dp));
    ans = solve(1, n);

    cout << ans << endl;

    return 0;
}

