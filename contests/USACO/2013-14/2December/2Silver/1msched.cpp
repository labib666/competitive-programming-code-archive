/*
ID: Labib Rashid
LANG: C++
TASK: msched
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

priority_queue <int> q;
vector <PII> v;

int main()
{
    //freopen ("1msched.txt","r",stdin);
    freopen ("msched.in","r",stdin);
    freopen ("msched.out","w",stdout);

    int n, i, j, k;
    PII p;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> j >> k;
        v.pb (make_pair(k,-j));
    }

    sort(v.begin(),v.end());

    for (i = 0; i < n; i++)
    {
        p = v[i];
        k = p.x;
        q.push(p.y);
        while(!q.empty()&&q.size() > k)
            q.pop();
    }

    int ans = 0;
    while(!q.empty()) {
        ans -= q.top();
        q.pop();
    }

    cout << ans << endl;


    return 0;
}
