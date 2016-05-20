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

using namespace std;

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    bool b[360];
    int i, j, k, n, q, now;

    cin >> n >> q;
    memset(b, 0, sizeof (b));
    b[0] = 1;

    for (i= 0; i < n; i++)
    {
        cin >> k;
        b[k] = 1;
    }

    for (i = 0; i < 360; i++)
    {
        for (j = 0; j < 360; j++)
        {
            if (b[j])
            {
                for (k = 0; k < 360; k++)
                {
                    if (b[k])
                    {
                        now = j + k;
                        now %= 360;
                        b[now] = 1;

                        now = j-k;
                        now += 360;
                        now %= 360;
                        b[now] = 1;
                    }
                }
            }
        }
    }

    while (q--)
    {
        cin >> k;
        if (b[k]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

