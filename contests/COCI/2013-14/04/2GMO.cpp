/*
ID: Labib Rashid
LANG: C++
TASK: GMO
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


int main()
{
    //freopen ("GMO.txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    string s1, s2;
    int n, m, i, j, k, c[30], cost = inf, cur;

    cin >> s1 >> s2;
    cin >> c['a'-'a'] >> c['c'-'a'] >> c['g'-'a'] >> c['t'-'a'];
    n = s1.size(); m = s2.size();

    for (i = 0; i < n; i++)
    {
        cur = 0;
        for (j = 0, k = i; j < m; j++)
        {
            if (k == n || s2[j] != s1[k]) cur += c[s2[j]-'A'];
            else if (s2[j] == s1[k]) k++;
            //cout << c[s2[j]-'A'] << endl;
        }
        //cout << cur << endl;
        cost = min(cost, cur);
    }

    cout << cost << endl;


    return 0;
}
