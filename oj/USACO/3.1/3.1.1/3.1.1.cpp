/*
USACO
mst
3.1.1 - agrinet
6.8.2013
*/
/*
ID: Labib Rashid
LANG: C++
TASK: agrinet
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
# define VI vector <int>
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

int a[100][100], c[100];
bool v[100];
priority_queue <PII> q;

int main()
{
    //freopen ("agrinet.txt","r",stdin);
    freopen ("agrinet.in","r",stdin);
    freopen ("agrinet.out","w",stdout);

    int i, j, k, n;
    PII now;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
            //cout << i << " " << j << " " << a[i][j] << endl;
        }
    }

    c[0] = 0;
    q.push (make_pair(0,0));

    while (!q.empty())
    {
        now = q.top();
        q.pop();

        if (v[now.y]) continue;
        v[now.y] = 1;
        c[now.y] = (-1)*now.x;
        //cout << "vis >> " << now.y << " " << now.x << endl;

        for (i = 0; i < n; i++)
        {
            if (v[i]) continue;
            q.push (make_pair((-1)*a[now.y][i],i));
        }
    }

    int ans = 0;
    for (i = 0; i < n; i++)
        ans += c[i];

    cout << ans << endl;

    return 0;
}

