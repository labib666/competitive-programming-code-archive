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

string s[30];

int main()
{
    freopen ("1.txt","r",stdin);
    //freopen (".in","r",stdin);
    freopen ("1.out","w",stdout);

    int t, tc = 0, n, i, j, k, mnx, mmx, mny, mmy;

    cin >> t;
    while (tc < t)
    {
        tc++;
        cin >> n;
        mmx = mmy = 0;
        mnx = mny = n-1;

        for (i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (s[i][j] == '#')
                {
                    mmx = max(i, mmx);
                    mnx = min(i, mnx);
                    mmy = max(j, mmy);
                    mny = min(j, mny);
                }
            }
        }

        if (mmx-mnx != mmy-mny) {printf("Case #%d: NO\n", tc ); continue;}

        bool fail = 0;
        for (i = mnx; i <= mmx; i++)
        {
            for (j = mny; j <= mmy; j++)
            {
                if (s[i][j] != '#')
                    fail = 1;
            }
        }

        printf("Case #%d: %s\n", tc, (fail) ? "NO" : "YES" );
    }


    return 0;
}
