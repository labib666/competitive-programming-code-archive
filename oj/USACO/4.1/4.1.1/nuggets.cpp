/*
ID: Labib Rashid
LANG: C++
TASK: nuggets
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

bool v[1000000];

int main()
{
    //freopen ("nuggets.txt","r",stdin);
    freopen ("nuggets.in","r",stdin);
    freopen ("nuggets.out","w",stdout);

    int i, j, k;
    int d[15], n;

    cin >> n;
    for (i=0;i<n;i++) {
        cin >> d[i];
    }

    sort (d,d+n);
    k = d[n-1]*d[n-1]+1;

    for (i=0,j=d[0];i<n;i++) {
        v[d[i]] = 1;
        j = gcd(j,d[i]);
    }
    if (j != 1) {
        cout << "0\n";
        return 0;
    }

    for (i = 0; i < n; i++) {
        for (j=0; j<k-d[i]; j++) {
            if (v[j]) v[j+d[i]] = 1;
        }
    }

    for (j = 0; j < k; j++)
        if (v[j]==0) i = j;

    cout << i << endl;


    return 0;
}
