/*
ID: Labib Rashid
LANG: C++
TASK: concom
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
# define maxn 105

using namespace std;

bool q[maxn][maxn];
int s[maxn][maxn];

void addown (int a, int b)
{
    int i, j, k;

    if (q[a][b])
        return;
    q[a][b] = 1;

    for (i = 1; i <= 100; i++)
        s[a][i] += s[b][i];

    for (i = 1; i <= 100; i++)
        if (q[i][a])
            addown(i,b);

    for (i = 1; i <= 100; i++)
        if (s[a][i] > 50)
            addown(a,i);

    return;
}

void own (int a, int b, int p)
{
    int k, i, j;

    for (i = 1; i <= 100; i++)
        if (q[i][a])
            s[i][b] += p;

    for (i = 1; i <= 100; i++)
        if (s[i][b] > 50)
            addown (i,b);

    return;
}

int main()
{
    freopen ("concom.in","r",stdin);
    freopen ("concom.out","w",stdout);

    int n, i, j, k;

    memset(q, 0, sizeof (q));
    memset(s, 0, sizeof (s));

    cin >> n;
    for (i = 1; i <= 100; i++)
        q[i][i] = 1;

    while (n--)
    {
        cin >> i >> j >> k;
        own(i,j,k);
    }

    for (i = 1; i <= 100; i++)
        for (j = 1; j <= 100; j++)
            if (q[i][j] && i != j)
                cout << i << " " << j << endl;

    return 0;
}

