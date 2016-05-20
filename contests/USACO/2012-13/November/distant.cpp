/*
ID: Labib Rashid
LANG: C++
TASK: distant
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


string s[35];
bool v[1000];
int d[1000][1000];

int main()
{
    //freopen (".txt","r",stdin);
    //freopen ("distant.in","r",stdin);
    //freopen ("distant.out","w",stdout);

    int n, a, b, i, j, k;

    cin >> n >> a >> b;

    for (i = 0; i < n; i++)
        cin >> s[i];

    memset(v, 0, sizeof (v));
    for (i = 0; i < n*n; i++)
    {
        for (j = 0; j < n*n; j++)
        {
            if (i != j)
                d[i][j] = inf;
            else
                d[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i][j] == '(') v[i*n + j] = 1;
        }
    }

    for (i = 0; i < n*n; i++)
    {
        if (i - n >= 0) d[i][i-n] = (v[i] && v[i-1] || !v[i] && !v[i-1]) ? a : b;
        if (i + n < n*n ) d[i][i+n] = (v[i] && v[i-1] || !v[i] && !v[i-1]) ? a : b;
        if (i % n > 0) d[i][i-1] = (v[i] && v[i-1] || !v[i] && !v[i-1]) ? a : b;
        if (i % n < n-1 ) d[i][i+1] = (v[i] && v[i-1] || !v[i] && !v[i-1]) ? a : b;
    }

    for (k = 0; k < n*n; k++)
    {
        for (i = 0; i < n*n; i++)
        {
            for (j = 0; j < n*n; j++)
            {
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    /*for (i = 0; i < n*n; i++)
    {
        for (j = 0; j < n*n; j++)
        {
            cout << d[i][j] << " " ;
        }
        cout << endl;
    }*/

    int ans = 0;

    for (i = 0; i < n*n; i++)
    {
        for (j = 0; j < n*n; j++)
        {
            if (ans < d[i][j])
            {
                ans = d[i][j];
                //cout << ans << " " << i << " " << j << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

