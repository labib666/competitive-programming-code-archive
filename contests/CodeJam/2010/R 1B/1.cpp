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

map <string, int> mp;

int tag (string s)
{
    int i, j, k = 0;
    string str;

    for (i = 1; i < s.size(); i++)
    {
        //str.clear();

        for (j = i; j < s.size(); j++)
        {
            if (s[j] == '/')
                break;
            str += s[j];
        }

        i = j;
        if (!mp[str]) {
            //cout << str << endl;
            mp[str] = 1;
            k++;
        }
        str += s[j];
    }

    return k;
}

int main()
{
    int t, tc = 0, n, m, i, j, k;
    string s;

    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.txt", "w", stdout);

    cin >> t;
    while (tc < t)
    {
        ++tc;

        cin >> n >> m;
        mp.clear();

        for (i = 0; i < n; i++)
        {
            cin >> s;
            j = tag(s);
        }

        k = 0;
        for (i = 0; i < m; i++)
        {
            cin >> s;
            j = tag(s);
            k += j;
        }

        printf ("Case #%d: %d\n", tc, k);
    }

    return 0;
}
