/*
ID: Labib Rashid
LANG: C++
TASK: dec
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

vector <PII> b[25];
int dp[(1<<20)], n, a[25][25];

int solve (int bt)
{
    if (dp[bt] != -1) return dp[bt];

    int i, j, k, cnt, sum = 0;

    cnt = bitcount(bt);
    if (cnt == 0) return dp[0] = 0;

    for (i = 0; i < n; i++)
    {
        if (((bt>>i)&1) == 0) continue;
        j = solve(bt^(1<<i)) + a[i][cnt-1];
        for (k = 0; k < b[cnt].size(); k++)
        {
            if (j >= b[cnt][k].x) j += b[cnt][k].y;
        }
        sum = max(sum, j);
    }
    return dp[bt] = sum;
}

int main()
{
    //freopen ("1dec.txt","r",stdin);
    freopen ("dec.in","r",stdin);
    freopen ("dec.out","w",stdout);

    int m, i, j, k;

    cin >> n >> m;
    while (m--)
    {
        cin >> i >> j >> k;
        b[i].pb (make_pair(j,k));
    }
    memset(dp, -1, sizeof(dp));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (i = 1; i <= 20; i++)
        sort(b[i].begin(), b[i].end());

    cout << solve((1<<n)-1) << endl;

    //for (i = 0; i < (1<<n); i++) cout << i << " " << dp[i] << endl;

    return 0;
}

