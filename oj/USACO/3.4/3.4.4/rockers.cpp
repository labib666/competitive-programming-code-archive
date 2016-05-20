/*
USACO
3.4.4 - Raucous Rockers
DP
1 Mar, 2014
/*
ID: Labib Rashid
LANG: C++
TASK: rockers
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
#define inf 1000000007
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

int a[25], n, m, t;
int dp[25][25][25];

int solve (int track, int disc, int time) {
    if (track == n) return 0;
    if (disc == m) return 0;

    int &ret = dp[track][disc][time];
    if (ret != -1) return ret;

    ret = solve(track+1, disc, time);
    ret = max(ret, solve(track, disc+1, t));
    if (a[track] <= time) ret = max(ret, solve(track+1, disc, time-a[track])+1);

    return ret;
}

int main()
{
    //freopen ("rockers.txt","r",stdin);
    freopen ("rockers.in","r",stdin);
    freopen ("rockers.out","w",stdout);

    int i, j, k;

    cin >> n >> t >> m;
    memset(dp, -1, sizeof (dp));

    for (i = 0; i < n ; i++) cin >> a[i];

    cout << solve (0, 0, t) << endl;


    return 0;
}

