/*
ID: Labib Rashid
LANG: C++
TASK: comehome
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

VI e[100], d[100];
priority_queue < PII > q;
bool v[100];

int main()
{
    //freopen ("comehome.txt","r",stdin);
    freopen ("comehome.in","r",stdin);
    freopen ("comehome.out","w",stdout);

    int i, j, k, n, a, b;
    char c1, c2;
    PII now;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> c1 >> c2 >> k;

        a = c1 - 'A', b = c2 - 'A';
        //cout << i << " " << j << endl;

        e[a].pb (b);
        e[b].pb (a);
        d[a].pb (k);
        d[b].pb (k);
    }

    q.push (make_pair (0, 25));

    while (!q.empty())
    {
        now = q.top();
        q.pop();

        if (v[now.y]) continue;
        v[now.y] = 1;
        if (now.y >= 0 && now.y <= 24) break;
        //cout << now.y << endl;

        for (i = 0; i < e[now.y].size(); i++)
        {
            if (v[e[now.y][i]]) continue;
            q.push (make_pair (now.x - d[now.y][i], e[now.y][i]));
            //cout << "pushed " << e[now.y][i] << endl;
        }
    }

    c1 = now.y;
    c1 += 'A';

    cout << c1 << " " << -1 * now.x << endl;

    return 0;
}

