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

bool vowel (char a)
{
    string s = "aeiou";

    for (int i = 0; i < 5; i++)
    {
        if (a == s[i])
            return true;
    }

    return false;
}

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.txt","w",stdout);

    ll t, tc = 0, sz, n, i, j, k, c, ans;
    string s;

    cin >> t;

    while (tc < t)
    {
        ++tc;

        cin >> s >> n;
        sz = s.size();

        k = -1, c = 0, ans = 0;

        for (i = 0, j = 0; j < n; j++)
        {
            if (!vowel(s[j])) c++;
        }
        j--;

        for (; j < sz; i++, j++)
        {
            if (c == n)
            {
                ans += (i - k) * (sz - j);
                k = i;
            }
            //cout << j << " " << ans << " " << c <<  endl;

            if (!vowel(s[i])) c--;
            if (j != sz-1)
                if (!vowel(s[j+1])) c++;
        }

        printf ("Case #%lld: %lld\n", tc, ans);
    }

    return 0;
}

