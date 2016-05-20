/*
ID: Labib Rashid
LANG: C++
TASK: humble
*/

// see 3.1.3.2 for a better solution

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

struct node {
    ll a;
    int b;
    bool operator < (const node &p) const {
        if (a < p.a) return false;
        return true;
    }
};

node make_node (ll a, int b)
{
    node p;
    p.a = a, p.b = b;
    return p;
}

ll p[100];
int c[100];
priority_queue < node > q;

int main()
{
    //freopen ("humble2.txt","r",stdin);
    freopen ("humble.in","r",stdin);
    freopen ("humble.out","w",stdout);

    int n, m, i, j, k, z;
    node now;
    ll cur, c1, c2;

    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        cin >> p[i];
        for (j = 0; j < 64; j++){
            if ((1ll << j) >= p[i]){
                c[i] = j;
                break;
            }
        }
        q.push(make_node(p[i], i));
    }

    k = 0;
    while (!q.empty())
    {
        now = q.top();
        q.pop();

        k++;
        if (k == m) break;
        //cout << k << " " << now.a << endl;

        for (j = 0; j < 64; j++){
            if ((1ll << j) >= now.a){
                z = j;
                break;
            }
        }

        ll lim;
        if (q.size() >= 500000) lim = 284456;

        for (i = now.b; i < n; i++)
        {
            c1 = now.a, c2 = p[i];

            if (z + c[i] > 34) continue;

            cur = c1 * c2;

            if (cur < (1ll << 32)) {
                if (q.size() >= 500000) if (cur > lim) continue;
                q.push(make_node(cur, i));
            }
        }
    }

    cout << now.a << endl;

    return 0;
}
