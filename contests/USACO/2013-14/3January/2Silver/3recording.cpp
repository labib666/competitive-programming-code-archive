/*
ID: Labib Rashid
LANG: C++
TASK: recording
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

struct data {
    int id, start, fin;
    bool operator < (const data &p) const
    {
        if (make_pair(fin,start) == make_pair(p.fin,p.start))
            return id < p.id;
        return make_pair(fin,start) < make_pair(p.fin,p.start);
    }
};

int dp[155][155][155], n;
data d[155];

int solve (int pos, int last1, int last2)
{
    if (pos == n+1) return 0;
    int &ret = dp[pos][last1][last2];
    if (ret != -1) return ret;

    ret = solve(pos+1, last1, last2);
    if (d[last1].fin <= d[pos].start) ret = max(ret, 1+solve(pos+1, pos, last2));
    if (d[last2].fin <= d[pos].start) ret = max(ret, 1+solve(pos+1, last1, pos));

    return ret;
}

int main()
{
    //freopen ("3recording.txt","r",stdin);
    freopen ("recording.in","r",stdin);
    freopen ("recording.out","w",stdout);

    int i, j, k, ans;

    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> d[i].start >> d[i].fin;
        d[i].id = i;
    }
    d[0].id = d[0].fin = d[0].start = 0;

    sort(d,d+n+1);
    memset(dp, -1, sizeof(dp));

    printf("%d\n", solve (1,0,0));


    return 0;
}
