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

int a[1050], q[1050], f[1050], cur;

void visit (int pos, int level)
{
    if (level == 0) return;
    visit(2*pos, level-1);
    q[cur++] = pos;
    visit(2*pos+1,level-1);
    return;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int k, i, j, n;

    cin >> k;
    n = (1<<k)-1;
    cur = 0;

    for (i = 0; i < n; i++)
        cin >> a[i];

    visit(1,k);

    for (i = 0; i < n; i++)
        f[q[i]] = a[i];

    for (i = 1, j = 1; i <= k; i++, j*=2)
    {
        int u, v;
        for (u=j,v = 0; u<j*2; u++, v++)
        {
            if (v) cout << " " << f[u];
            else cout << f[u];
        }
        cout << endl;
    }


    return 0;
}
