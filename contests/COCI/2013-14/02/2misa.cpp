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

int X[] = {0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};
int v[55][55];

int check (int px, int py)
{
    int x, y, cnt = 0, i;

    for (i = 0; i < 8; i++)
    {
        x = px+X[i], y = py+Y[i];
        if (v[x][y]) cnt++;
    }

    return cnt;
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int r, c, i, j, k, l, ans = 0, cnt = 0;
    string s, str;

    cin >> r >> c;

    for (i = 1; i <= r; i++)
    {
        cin >> str;
        s = "." + str;
        for (j = 1; j <= c; j++)
            if (s[j] == 'o') v[i][j] = 1;
    }

    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (v[i][j] == 0) {
                ans = max(check(i, j), ans);
            }
            else cnt += check (i, j);
        }
    }

    cout << ans+cnt/2 << endl;


    return 0;
}
