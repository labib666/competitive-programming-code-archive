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

int dp[(1<<24)], tmp[(1<<24)];

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, k, m, i, j, p;
    int v, v1;

    cin >> n >> k >> m;
    dp[0] = 1;
    m = (1<<m);

    for (i=0;i<n;i++) {
        fill (tmp, tmp+m, 0);
        for (j=0;j<m;j++) {
            if (dp[j]==0) continue;
            v = (j*33)%m;
            for (p=1;p<=26;p++) {
                v1 = (v^p);
                tmp[v1] += dp[j];
            }
        }
        for (j=0;j<m;j++) dp[j] = tmp[j];
    }

    cout << dp[k] << endl;


    return 0;
}
