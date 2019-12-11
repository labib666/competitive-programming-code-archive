/*
ID: Labib Rashid
LANG: C++
TASK: prefix
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

using namespace std;

int n, dp[200005];
string s, str, dot = ".";
vector <string> p;
vector <int> sz;

int solve (int at)
{
    if (at == n) return 0;

    if (dp[at] != -1)
        return dp[at];

    int ans, a, i, j, k;
    bool tr;
    ans = 0;

    for (i = 0; i < p.size(); i++)
    {
        tr = 1;
        for (j = 0; j < sz[i]; j++)
        {
            if (s[at + j] != p[i][j])
            {
                tr = 0;
                break;
            }
        }
        if (!tr) continue;
        a = sz[i] + solve(at + sz[i]);
        ans = max(ans, a);
    }

    return dp[at] = ans;
}

int main()
{
    freopen ("prefix.in","r",stdin);
    freopen ("prefix.out","w",stdout);

    int i, j, k;

    while (1)
    {
        cin >> s;
        if (s == dot) break;
        i = s.size();
        p.pb (s);
        sz.pb (i);
    }

    s.clear();
    while (cin >> str)
        s += str;
    n = s.size();

    memset(dp, -1, sizeof (dp));

    k = solve (0);

    cout << k << endl;

    return 0;
}

