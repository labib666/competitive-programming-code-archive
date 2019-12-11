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

bool cmp (pair <ll,ll> a, pair <ll,ll> b) {
    return make_pair(a.x,-a.y) < make_pair(b.x,-b.y);
}

pair <ll,ll> p[300005];
ll s[300005];
stack <ll> q;

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    ll n, ans=1, i, j, k;

    cin >> n;
    for(i=0;i<n;i++) {
        cin >> j >> k;
        p[i].x = j-k;
        p[i].y = j+k;
    }

    sort(p,p+n,cmp);
    for(i=0;i<n;i++) s[i] = p[i].y-p[i].x;

    for(i=0;i<n;i++) {
        while (!q.empty() && p[q.top()].y <= p[i].x) {
            q.pop();
        }
        if (!q.empty()) s[q.top()] -= s[i];
        q.push(i);
    }

    for(i = 0; i < n; i++) {
        if (s[i] != 0) ans += 1;
        else ans += 2;
    }

    cout << ans << endl;

    return 0;
}
