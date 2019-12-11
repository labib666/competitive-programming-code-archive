/*
USACO
brute force, simulation
3.2.3 - spinning wheels
21.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: spin
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

int bitcount (int a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}

PII a[5][5];
int s[5], sz[5];

bool check ()
{
    int i, j, k;
    int v[360];
    memset(v,0,sizeof (v));

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < sz[i]; j++)
        {
            //cout << i << " " << j << " " << (a[i][j].x) % 360 << " " << (a[i][j].y)%360 << endl;
            for (k = a[i][j].x; k <= a[i][j].y; k++)
            {
                v[(k%360)]++;
            }
        }
    }

    for (i = 0; i < 360; i++){
        if (v[i] == 5) {
            //cout << i << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen ("spin.txt","r",stdin);
    freopen ("spin.in","r",stdin);
    freopen ("spin.out","w",stdout);

    int i, j, k, n = 5, t;

    for (i = 0; i < n; i++)
    {
        cin >> s[i] >> sz[i];
        //cout << i << " " << s[i] << endl;
        for (j = 0; j < sz[i]; j++){
            cin >> a[i][j].x >> a[i][j].y;
            a[i][j].y = (a[i][j].x + a[i][j].y);
        }
    }

    for (t = 0; t <= 360; t++){
        //cout << t << endl;

        if (check ()) {
            cout << t << endl;
            return 0;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < sz[i]; j++){
                a[i][j].x = (a[i][j].x + s[i]);
                a[i][j].y = (a[i][j].y + s[i]);
            }
        }
    }

    cout << "none\n";

    return 0;
}


