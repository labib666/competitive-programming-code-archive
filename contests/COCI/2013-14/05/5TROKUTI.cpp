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

ll gcd (ll a, ll b)
{
    if (a < 0) a *= (-1);
    if (b < 0) b *= (-1);
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

map < pair <ll,ll> , ll > m;
set < pair <ll,ll> > s;
set < pair <ll,ll> >::iterator it;
ll sum[300005], sum2[300005], sum3[300005];

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, c, u, i, j, k;

    cin >> u;
    while (u--)
    {
        cin >> i >> j >> k;
        if (i < 0 && j < 0) i *= (-1), j *= (-1);
        if (i < 0 && j >= 0) i *= (-1), j *= (-1);
        ll g = gcd(i, j);
        i /= g, j /= g;
        pair <ll, ll> p = make_pair(i, j);
        m[p]++;
        s.insert(p);
    }

    n = s.size();
    for (i = 0, it = s.begin(); i < n; i++, it++)
    {
        sum[i] = m[*it];
    }

    for (i = n-1, c = 0; i >= 0; i--)
    {
        sum2[i] = c*sum[i]; sum2[i] %= inf;
        c += sum[i]; c %= inf;
    }

    for (i = n-1, c = 0; i >= 0; i--)
    {
        sum3[i] = c*sum[i]; sum3[i] %= inf;
        c += sum2[i]; c %= inf;
    }

    for (i = 0, c = 0; i < n; i++)
    {
        c += sum3[i];
        c %= inf;
    }

    cout << c << endl;


    return 0;
}
