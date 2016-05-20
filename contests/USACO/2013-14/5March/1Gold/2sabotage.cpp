/*
ID: Labib Rashid
LANG: C++
TASK: sabotage
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

double a[100005], b[100005];

int main()
{
    //freopen ("2sabotage.txt","r",stdin);
    freopen ("sabotage.in","r",stdin);
    freopen ("sabotage.out","w",stdout);

    int n, i, j, k = 50;
    double hi=0.0, lo=10001.0, mid, sum, cur, tot, ans;

    cin >> n;
    for (i=0;i<n;i++) {
        cin >> a[i];
        hi = max(a[i],hi);
        lo = min(a[i],lo);
    }

    while (k--) {
        mid = (hi+lo)/2.0; tot = 0.0;
        for (i=0;i<n;i++) {b[i] = a[i]-mid; tot += b[i];}
        sum = 0.0; cur = 0.0;
        for (i=1;i<n-1;i++){
            cur = max(0.0,cur+b[i]);
            sum = max(sum,cur);
        }
        for (i=1, cur=-1e9;i<n-1;i++){
            cur = max(cur,b[i]);
        }
        if (cur < 0.0) sum = cur;
        if (sum > tot) hi = mid;
        else lo = mid;
    }

    ans = (hi+lo)/2;
    printf ("%.3lf\n", ans);

    return 0;
}
