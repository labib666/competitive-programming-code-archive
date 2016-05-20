/*
ID: Labib Rashid
LANG: C++
TASK: fracdec
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

int v[100005], t[100005], a, b;
queue < PII > q;
stringstream ss;
string s;
PII p;

void process (int ns, int ne)
{
    int i;
    for (i = 1; i < ns; i++)
        ss << (t[i]*10) / b;

    ss << "(";
    for (i = ns; i < ne; i++)
        ss << (t[i]*10) / b;
    ss << ")";

    return;
}

void process2 (int ne)
{
    int i;
    for (i = 1; i < ne; i++)
        ss << (t[i]*10) / b;
    return;
}

int main()
{
    //freopen ("fracdec.txt","r",stdin);
    freopen ("fracdec.in","r",stdin);
    freopen ("fracdec.out","w",stdout);

    int i, j, k;

    cin >> a >> b;

    if (a % b == 0) {
        cout << a/b << ".0\n";
        return 0;
    }

    ss << a/b;
    ss << ".";

    q.push (make_pair (a % b, 1) );

    while (!q.empty ())
    {
        p = q.front();
        q.pop();

        if (v[p.x]) {
            process(v[p.x], p.y);
            break;
        }
        else if (!p.x) {
            process2(p.y);
            break;
        }

        v[p.x] = p.y;
        t[p.y] = p.x;

        k = p.x * 10;
        k %= b;

        q.push (make_pair (k, p.y+1));
    }

    ss >> s;

    for (i = 0; i < s.size(); i++)
    {
        if (i && i%76 == 0) cout << endl;

        cout << s[i];
    }
    cout << endl;

    return 0;
}

