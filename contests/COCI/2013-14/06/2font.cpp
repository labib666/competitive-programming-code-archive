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

int a[30];

int recur (int pos, int bit) {
    if (bit == (1<<26)-1) return (1<<(pos+1));
    if (pos < 0) return 0;
    return recur(pos-1,(bit|a[pos]))+recur(pos-1,bit);
}

int main()
{
    //freopen (".txt","r",stdin);
    //freopen (".in","r",stdin);
    //freopen (".out","w",stdout);

    int n, i, j, k, ans = 0;
    string s;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        k = s.size();
        for(j=0;j<k;j++) {
            int p = s[j]-'a';
            a[i] |= (1<<p);
        }
    }

    cout << recur(n-1,0) << endl;

    return 0;
}
