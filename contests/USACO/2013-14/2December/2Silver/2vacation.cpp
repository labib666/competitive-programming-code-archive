/*
ID: Labib Rashid
LANG: C++
TASK: vacation
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
#define inf 100000000000000007ll
#define pi 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define eps 1e-9

using namespace std;

ll a[205][205]; // cost i->j

int main()
{
    //freopen ("2vacation.txt","r",stdin);
    freopen ("vacation.in","r",stdin);
    freopen ("vacation.out","w",stdout);

    ll n, m, k, qu, i, j, u, vc, c;

    cin >> n >> m >> k >> qu;

    //initialise array a & identify
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            (j==i) ? a[i][j] = 0 : a[i][j] = inf;
        

    for ( i = 0; i < m; i++)
    {
        cin >> u >> vc >> c;
        a[u][vc] = min(c,a[u][vc]);
    }

    for (u = 1; u <= n; u++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] > a[i][u] + a[u][j])
                    a[i][j] = a[i][u] + a[u][j];
            }
        }
    }


    ll ans = 0, cnt = 0;
    while (qu--)
    {
        cin >> i >> j;
        ll tmp = inf;
        for (u=1;u<=k;u++) 
        	tmp = min (tmp, a[i][u]+a[u][j]);
        if (tmp < inf) {
        	ans += tmp;
        	cnt++;
        }
    }

    cout << cnt << endl;
    cout << ans << endl;


    return 0;
}
