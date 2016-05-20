#include <vector>
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

vector <int> key[405], t[205], l;
int v[205];

void dfs (int k, vector <int> a) {
    int i, j;
    for (i = 0; i < (int)key[k].size(); i++)
    {
        vector <int> a2;
        v[key[k][i]] = 1;
        for (j=0; j < (int)a.size(); j++)
            a2.pb (a[j]);
        a2.erase(a2.begin() + i);
    }
}

int main()
{
    int t, tc = 0, n, m, i, j, k, a;

    cin >> t;
    while (tc < t) {
        ++tc;

        cin >> m >> n;

        for (i = 0; i < m; i++)
        {
            cin >> j;
            l.pb (j);
        }

        for (i = 0; i < m; i++)
        {
            cin >> j;
            key[j].pb (i);

            cin >> j;
            for (k = 0; k < j; k++) {
                cin >> a;
                t[i].pb (a);
            }
        }
        memset(v, 0, sizeof (v));

        for (i = )
    }
    return 0;
}

