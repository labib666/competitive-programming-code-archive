/*
ID: Labib Rashid
LANG: C++
TASK: fcount
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

VI v;
int n;
PII a[505];

bool check (int pos) {
    queue <int> p, q, r;
    int i, j, k;
    for (i=0; i <= n; i++) {
        if (i == pos) continue;
        p.push(a[i].x);
    }

    while (!p.empty()) {

        k = p.front(); p.pop();
        if (k > p.size()) return 0;

        for (i=0;i<k;i++) {
            j = p.front(); p.pop();
            if (j-1 != 0) q.push(j-1);
        }

        while (!p.empty() || !q.empty()) {
            if (p.empty()) {
                k = q.front();
                q.pop(); r.push(k);
                continue;
            }
            if (q.empty()) {
                k = p.front();
                p.pop(); r.push(k);
                continue;
            }
            (p.front() > q.front()) ? r.push(p.front()) : r.push(q.front());
            (p.front() > q.front()) ? p.pop() : q.pop();
        }
        while (!r.empty()) {
            p.push(r.front());
            r.pop();
        }
    }
    return 1;
}

int main()
{
    //freopen ("3_Gol_fcount.txt","r",stdin);
    freopen ("fcount.in","r",stdin);
    freopen ("fcount.out","w",stdout);

    int i, j, k=0;

    cin >> n;
    for (i = 0; i <= n; i++) {
        cin >> a[i].x; k += a[i].x;
        a[i].y = i+1;
    }

    sort (a, a+n+1);
    reverse (a, a+n+1);

    for (i = 0; i <= n; i++) {
        if ((k-a[i].x)%2) continue;

        if (check(i)) {
            v.pb (a[i].y);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (i=0;i<v.size();i++) cout << v[i] << endl;


    return 0;
}
