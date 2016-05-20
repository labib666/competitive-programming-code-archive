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

string s[105];

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, i, j, k;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> s[i];

    bool pass = 0;
    for (i = 0; i < n; i++)
    {
        string rev = s[i];
        reverse(rev.begin(), rev.end());
        for (j = 0; j < n; j++)
        {
            if (s[j] == rev) {
                pass = 1;
                break;
            }
        }
        if (pass) break;
    }

    int len = s[i].size();
    cout << len << " " << s[i][len/2] << endl;


    return 0;
}
