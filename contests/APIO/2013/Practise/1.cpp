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

int a[10000000], n;

ll sieve ()
{
    int i, j, k;
    ll sum = 0;
    memset(a, -1, sizeof (a));

    for (i = 2; i*i <= n; i++)
    {
        if (a[i] != -1) continue;
        a[i] = 2+i;
        sum += 2+i;

        for (j = i; i*j <= n; j++)
        {
            if (a[i*j] == -1){
                a[i*j] = i;
                sum += i;
            }
        }
    }

    //cout << sum << endl;

    for (; i <= n; i++)
    {
        if (a[i] != -1) continue;
        a[i] = 2+i;
        sum += 2+i;
    }

    sum += 1;

    //for (int i = 2; i <= n; i++)
        //cout << i << " " << a[i] << endl;

    return sum;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    cin >> n;

    if (n == 2) cout << 0 << endl;
    else if (n == 3) cout << 5 << endl;
    else cout << sieve() << endl;

    return 0;
}

