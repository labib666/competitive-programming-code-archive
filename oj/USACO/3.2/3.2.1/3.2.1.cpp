/*
USACO
3.2.1 - Factorials
NT
21.8.2013
/*
ID: Labib Rashid
LANG: C++
TASK: fact4
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

int a[4225];

int main()
{
    //freopen ("fact4.txt","r",stdin);
    freopen ("fact4.in","r",stdin);
    freopen ("fact4.out","w",stdout);

    int i, j, k, n, c;

    cin >> n;

    c = 0;
    for (i = 1; i <= n; i++)
        a[i] = i;

    for (i = 5; i <= n; i*=5)
    {
        for (j = 1; j*i <= n; j++)
        {
            c++;
            a[j*i] /= 5;
        }
    }

    for (i = 2; i <= n; i++)
    {
        for (j = 1; j*i <= n && c; j++, c--)
        {
            a[j*i] /= 2;
        }
    }

    k = 1;
    for (i = 1; i <= n; i++){
        k = (k*a[i]) % 10;
    }

    cout << k << endl;

    return 0;
}


