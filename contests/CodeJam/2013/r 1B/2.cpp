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
# include <fstream>
# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007
# define pi 2*asin(1)

using namespace std;

int n, dp[10000][6], sz = 521196, ssz[1000000];
string s[1000000], str;


// library in
void takeinput ()
{
    int i;
    ifstream fin("garbled_email_dictionary.txt");

    for (i = 0; i < sz; i++) {
        fin >> s[i];
        ssz[i] = s[i].size();
        i++;
    }

    fin.close();
}

//finding match
pair <int, int> match(int at, int p, int a)
{
    int ans = 0, sz1, sz2, i;

    sz1 = ssz[at];
    sz2 = n - p;

    if (sz1 > sz2)
        return make_pair (-1,0);

    for (i = 0; i < sz1; i++)
    {
        if (s[at][i] != str[p+i])
        {
            if (p+i-a < 5) return make_pair (-1,0);
            ans ++;
            a = p+i;
        }
    }

    return make_pair(ans, a);
}


int solve (int p, int c)
{
    //cout << p << " " << c << endl;
    if (p == n)
        return 0;

    int d = min (5, p-c);
    if (dp[p][d] != -1)
        return dp[p][d];

    dp[p][d] = inf;
    int ans = inf, i, j;
    pair <int, int> k;

    for (i=0; i < sz; i++)
    {
        k = match(i, p, c);
        if (k.x == -1) continue;

        ans = min (ans, k.x + solve(p+ssz[i], k.y));
    }

    return dp[p][d] = ans;
}


int main()
{
    int t, tc = 0, i, j, k, ans;

    takeinput();

    //freopen (".txt","r",stdin);
    //freopen (".txt","w",stdout);

    cin >> t;
    while (tc < t)
    {
        ++ tc;

        cin >> str;
        memset(dp, -1, sizeof (dp));
        n = str.size();

        ans = solve (0,-5);
        printf ("Case #%d: %d\n", tc, ans);
    }

    return 0;
}

