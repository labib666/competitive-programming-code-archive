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
    //cout << a << "  "  << b << endl;
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (ll a)
{
    int i;
    for (i = 0; a > 0; i++) a &= (a-1);
    return i;
}


int a[1005], b[1005], c[1005];
map <string , bool > m;

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, r, x1[1005], x2[1005], y1[1005], y2[1005], i, j, k;

    cin >> r >> n;

    for (i = 0; i < n; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];


    for (i = 0; i < n; i++)
    {
        a[i] = y1[i] - y2[i];
        b[i] = (-1)*(x1[i]-x2[i]);
        c[i] = (-1) * (x1[i]*a[i] + y1[i]*b[i]);
    }

    int ans = n + 1;

    for (i = 0; i < n; i++)
    {
        m.clear();

        for (j = 0; j < i; j++)
        {
            //if (i == j) continue;

            if (a[i]*b[j] == a[j]*b[i]) continue;

            int p, q1, q2;

            p = a[i]*b[j] - a[j]*b[i];

            q1 = b[i]*c[j] - b[j]*c[i];

            q2 = c[i]*a[j] - c[j]*a[i];

            if ( (q1*q1 + q2*q2) > p*p*r*r )  continue;


            string s;
            stringstream ss;
            int g;
            cout << "made it\n" ;

            g = gcd (abs(q1),abs(p));
            //cout << g << endl;
            ss << q1/g;
            ss << ",";
            ss << p/g;

            g = gcd (abs(q1),abs(p));
            ss << q2/g;
            ss << ",";
            ss << p/g;

            cout << "made it\n" ;

            ss >> s;

            if (m[s]) continue;
            m[s] = 1;
            ans++;

            cout << "made it\n" ;
        }
    }
    cout << ans << endl;


    return 0;
}

