/*
ID: Labib Rashid
LANG: C++
TASK: nasljedstvo
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


int main()
{
    //freopen ("nasljedstvo.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, r, i, j, k, mx, mn;

    //while (cin >> n)
    {
        cin >> n;
        cin >> r;

        mx = 0, mn = 300;

        for (i = 0; i <= 300; i++)
        {
            j = r + i;
            if (j - j/n == r) mx = max(mx, j), mn = min(mn, j);
        }

        cout << mn << " " << mx << endl;
    }


    return 0;
}
