/*
ID: Labib Rashid
LANG: C++
TASK: bbreeds
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
# define inf 1000000007
# define pi 2*asin(1)
# define PII pair<int,int>
# define loop(a,s,e) for(a=s;a<e;a++)
# define rloop(a,s,e) for(a=s-1;a>=e;a--)

using namespace std;

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (ll a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}


string s;
int n, cs[1005];
int dp[1005][1005];

int solve (int at, int sum)
{
    if (at == n) {
        if (!sum) return 1;
        return 0;
    }

    if (dp[at][sum] != -1) return dp[at][sum];

    if (sum < 0 || cs[at] - sum < 0) return dp[at][sum] = 0;

    if (s[at] == '(')
            dp[at][sum] = (solve(at+1, sum + 1) + solve(at+1, sum))%2012;
    else
            dp[at][sum] = (solve(at+1, sum - 1) + solve(at+1, sum))%2012;

    return dp[at][sum];
}

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("bbreeds.in","r",stdin);
    freopen ("bbreeds.out","w",stdout);

    int i, j, k;

    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof (dp));

    for (i = 0; i < n; i++)
    {
        if (s[i] == '(') cs[i+1]++;
        if (s[i] == ')') cs[i+1]--;
        cs[i+1] += cs[i];
    }

    cout << solve (0,0) << endl;

    return 0;
}

